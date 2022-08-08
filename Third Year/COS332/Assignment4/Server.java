// u20734621 - Matthew Gotte, u20662302 - Ryan Healy
import java.net.*;
import java.nio.file.Files;
import java.io.*;
import java.util.Base64;
import java.util.Date;
import java.util.Scanner;
import java.util.regex.Pattern;

public class Server
{
    public Socket client;
    public ServerSocket server;
    //public BufferedReader in;
    public InputStreamReader in;
    public OutputStream out;
    public String calc;
    public String ans;
    public int portNumber;
    public String serverAddress;
    public String[] names;
    public String[] numbers;
    public int size;
    public String uploadError = "";
    public String searchError = "";

    public Server(int pn)
    {
        try
        {
            this.client = null;
            this.portNumber = pn;
            this.server = new ServerSocket(portNumber);;
            this.in = null;
            this.out = null;
            this.calc = " ";
            this.ans = " ";
        }
        catch (IOException i)
        {
            System.out.println(i);
        }
        
    }

    public void runServer()
    {
        try
        {
            client = server.accept();
            //in = new BufferedReader(new InputStreamReader(client.getInputStream(), "UTF-8"));
            in = new InputStreamReader(client.getInputStream(), "UTF-8"); 

            out = client.getOutputStream();

            this.uploadError = "";
            this.searchError = "";

            serveReq();
 
            client.close();
            in.close();
            out.close();
        }
        catch(IOException i)
        {
            System.out.println("IOException in run() : " + i);
        }
    }
    
    public void serveReq() 
    {
        try
        {
            System.out.println("Serve Request");
            String method, uri, version;
            String req = getRequestString();
            System.out.println(req);
            Scanner splitter = new Scanner(req).useDelimiter("\r\n");
            
            String line = splitter.next();
            Scanner splitter2 = new Scanner(line).useDelimiter(" ");

            method = splitter2.next(); 
            uri = splitter2.next();
            version = splitter2.next();
            splitter2.close();

            line = splitter.next();
            splitter2 = new Scanner(line).useDelimiter("Host: ");
            this.serverAddress = splitter2.next(); 
            
            splitter.close();
            splitter2.close();

            // check for valid version (protocol):
            if (version.equals("HTTP/1.1"))
            {
                //check for valid request method:
                if (method.equals("GET"))
                {
                    GETMethod(uri);
                }
                else if (method.equals("POST"))
                {
                    Scanner splitter3 = new Scanner(req).useDelimiter("\r\n");

                    do
                    {
                        line = splitter3.next();
                    }
                    while (line.indexOf("Content-Type: multipart/form-data; boundary=") == -1);

                    splitter3.close();
                    
                    POSTMethod(req, line.substring("Content-Type: multipart/form-data; boundary=".length()));
                }
                else if (method.equals("PUT") || method.equals("PATCH") || method.equals("DELETE") )
                {
                    sendError(405); // Method not allowed  
                }
                else
                {
                    sendError(400); // Bad or malformed request
                }
            }
            else
            {
                sendError(505); // HTTP version not supported
            }            
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }

    public void GETMethod(String uri)
    {
        if (uri.charAt(0) == '/')
        {
            connectDatabase();
            String deleteRegEx = "/\\?type=delete&delete=[0-9]{10}";
            String searchRegEx = "/\\?type=search&search=.*";

            if (uri.length() == 1)
            {
                sendResponse('/');
            }
            else if (Pattern.matches(deleteRegEx, uri))
            {
                String numToDelete = uri.substring("/?type=delete&delete=".length());
                int i = searchDB(numToDelete);

                deleteEntry(i);

                sendResponse('/');
            }
            else if (Pattern.matches(searchRegEx, uri))
            {
                String searchTerm = uri.substring("/?type=search&search=".length());

                if (searchTerm.length() > 0)
                {
                    int i = searchDB(searchTerm);

                    if (i >= 0)
                    {
                        names[0] = names[i];
                        numbers[0] = numbers[i];
                        this.size = 1;
                    }
                    else
                    {
                        this.searchError = "Error: search term not found in the database";
                        this.size = 0;
                    }
                }

                sendResponse('/');
            }
            else
            {
                sendError(404); // not found
            }
        }
        else
        {
            sendError(400); // Bad or malformed request
        }
    }

    public void POSTMethod(String req, String boundry)
    {
        Scanner splitter = new Scanner(req).useDelimiter("--" + boundry); // for some reason the boundry uses more dahses than it says
        splitter.next();
        String line = splitter.next();
        Scanner splitter2 = new Scanner(line).useDelimiter("\r\n");
        String newName, newNumber, newImage;

        splitter2.next();
        splitter2.next();
        newName = splitter2.next();
        splitter2.close();

        line = splitter.next();
        splitter2 = new Scanner(line).useDelimiter("\r\n");
        splitter2.next();
        splitter2.next();
        newNumber = splitter2.next();
        splitter2.close();

        line = splitter.next();
        newImage = line.substring(line.indexOf("image/png") + 13, line.length()-2);

        splitter.close();

        // this looks messy but it works
        if (Pattern.matches("([a-zA-Z]| |[0-9])+", newName))
        {
            if (Pattern.matches("[0-9]{10}", newNumber))
            {
                if (searchDB(newName) == -1)
                {
                    if (searchDB(newNumber) == -1)
                    {
                        writeDB(newName, newNumber, newImage);
                    }
                    else
                    {
                        this.uploadError = "Error: number already exists in the database";
                    }
                }
                else
                {
                    this.uploadError = "Error: name already exists in the database";
                }
            }
            else
            {
                this.uploadError = "Error: invalid number";
            }
        }
        else
        {
            this.uploadError = "Error: invalid name";
        }

        sendResponse('/');
    }

    private int searchDB(String searchTerm)
    {
        for (int i = 0; i < this.size; i++) 
        {
            if (searchTerm.equals(names[i]) || searchTerm.equals(numbers[i]))
            {
                return i;
            }
        }
        return -1;
    }

    private void deleteEntry(int index)
    {
        File deleteFile = new File("images/" + numbers[index] + ".png");
        deleteFile.delete();

        for (int i = index; i < this.size-1; i++) 
        {
            names[i] = names[i+1];
            numbers[i] = numbers[i+1];
        }

        this.size--;
        writeDB();
    }

    // writes the database if no new entries are added
    private void writeDB()
    {
        try 
        {
            FileWriter w = new FileWriter("db.txt");
            w.write("" + this.size);

            for (int i = 0; i < this.size; i++)
            {
                String line = "\n";
                line += this.names[i];
                line += ",";
                line += this.numbers[i];
                w.write(line);
            }

            w.close();
        } 
        catch (IOException e) 
        {
            System.out.println("> An error occurred.");
            e.printStackTrace();
        }
    }

    // writes the databse if a new entry is added
    private void writeDB(String newName, String newNumber, String imageData)
    {
        try 
        {
            FileWriter w = new FileWriter("db.txt");
            w.write("" + (this.size+1));
            String line = "\n";
            line += newName;
            line += ",";
            line += newNumber;
            w.write(line);

            for (int i = 0; i < this.size; i++)
            {
                line = "\n";
                line += this.names[i];
                line += ",";
                line += this.numbers[i];
                w.write(line);
            }

            w.close();

            // doesnt work with FileOutputStream or FileWriter
            FileOutputStream nw = new FileOutputStream("images/" + newNumber + ".png");
            nw.write(imageData.getBytes());

            nw.close();
            connectDatabase();
        } 
        catch (IOException e) 
        {
            System.out.println("> An error occurred.");
            e.printStackTrace();
        }
    }

    private boolean connectDatabase()
    {
        try 
        {
            Scanner scLine = new Scanner(new File("db.txt"));
            this.size = Integer.parseInt(scLine.nextLine());
            int count = 0;

            this.names = new String[size];
            this.numbers = new String[size];
            
            while (scLine.hasNextLine()) 
            {
                Scanner scDelim = new Scanner(scLine.nextLine());
                scDelim.useDelimiter(",");

                this.names[count] = scDelim.next();
                this.numbers[count++] = scDelim.next();

                scDelim.close();
            }
            scLine.close();
        } 
        catch (FileNotFoundException e) 
        {
            System.out.println("> An error occurred.");
            e.printStackTrace();
            return false;
        }

        return true;
    } 

    public void sendResponse(char href)
    {
        try
        {
            String response = "HTTP/1.1 200 OK\r\n";
            response += "Server: " + this.serverAddress + "\r\n";
            response += "Date: " + new Date() + "\r\n";
            response += "Content-Type: text/html\r\n";        

            //String tempImage = "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";
            String page = "<!DOCTYPE html><html lang='en'> <head> <title>Assignment 4</title> <link rel='icon' href='data:'> <meta http-equiv='Content-Type' content='text/html; charset='UTF-8'> </head> <body> <h1>Upload a contact:</h1> <div>" + this.uploadError + "<br/></div> <form method='POST' action='http://" + this.serverAddress + "/' enctype='multipart/form-data' charset='UTF-8'> Name: <input type='text' name='name' required/> <br/><br/> Tel. Number: <input type='tel' name='tel' required/> <br/><br/> Image: <input type='file' value='Upload' name='upload' id='upload' required/> <br/><br/> <input type='submit'> </form> <br/> <h1>Contacts</h1> <div>" + this.searchError + "<br/></div> <form method='GET' action='http://" + this.serverAddress + "/' enctype='multipart/form-data' > <input type='hidden' name='type' value='search'/> <input type='text' name='search'/> <input type='submit' value='Search'/> </form> <br/> <br/> <table border='1'> <tr> <th>Picture</th> <th>Name</th> <th>Tel No.</th> <th>Delete</th> </tr>";
            String tempImage = Base64.getEncoder().encodeToString(Files.readAllBytes(new File("images/finaltestimage.png").toPath()));

            for (int i = 0; i < this.size; i++)
            {
                page += "<tr><td><img src='data:image/png;base64," + tempImage + "' alt='no image'/></td><td>";
                page += this.names[i];
                page += "</td><td>";
                page += this.numbers[i];
                page += "</td><td> <form method='GET' action='http://";
                page += this.serverAddress;
                page += "/' enctype='multipart/form-data' > <input type='hidden' name='type' value='delete'/> <input type='hidden' name='delete' value='";
                page += this.numbers[i];
                page += "'/> <input type='submit' value='Delete'/> </form> </td></tr>";
            }
            
            page += "</table> </body></html>";

            response += "Content-length: " + page.length() + "\r\n";
            response += "\r\n\r\n";      
            response += page;
        
            out.write(response.getBytes());
            out.flush();
        }
        catch (IOException i)
        {
            System.out.println(i);
        }
    }

    public void sendError(int code)
    {
        String header = "HTTP/1.1 ";
        switch (code) 
        {
            case 400: //Bad or malformed request
                header += code + " Bad Request\r\n";
                break;
            case 404: //uri was not found
                header += code + " Not Found\r\n";
                break;
            case 405: //Method not allowed
                header += code + " Method Not Allowed\r\n";
                header += "Allow: GET\r\n";
                break;
            case 505: //version not supported
                header += code + " HTTP Version Not Supported\r\n";
                break;
        }

        try 
        {
            File file = new File(code + ".html");
            int fileLength = (int) file.length();
            String content = "text/html";
            byte fileData[] = Files.readAllBytes(file.toPath());

            out.write((header).getBytes());
            out.write(("Server: 0.0.0.0:8080\r\n").getBytes());
            out.write(("Date: " + new Date() + "\r\n").getBytes());
            out.write(("Content-type: " + content + "\r\n").getBytes());
            out.write(("Content-length: " + fileLength + "\r\n").getBytes());
            out.write(("\r\n\r\n").getBytes()); // blank line between headers and content, very important !
            //out.flush(); // flush character output stream buffer
            
            out.write(fileData, 0, fileLength);
            out.write(("\r\n\r\n").getBytes());
            out.flush();
        }
        catch(IOException i) 
        {
            System.out.println(i);
        }
        
    }

    public String getRequestString() 
    {
        String o = "";
        try 
        {
            while(in.ready()) 
            {
                o += (char) in.read();
            }
            
        } 
        catch (IOException e) 
        {
            e.printStackTrace();
        }
        
        return o;
    }

    public static void main(String[] args) 
    {
        try
        {
            Server server = new Server(8081);
            while(true)
            {
                //Server serverConnect = new Server(server.accept());
                server.runServer();
            }
        }
        catch (Exception i)
        {
            System.out.println(i);
        }
    }
}