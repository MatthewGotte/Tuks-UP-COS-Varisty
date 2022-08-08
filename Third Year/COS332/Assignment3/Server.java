// u20734621 - Matthew Gotte, u20662302 - Ryan Healy
import java.net.*;
import java.nio.file.Files;
import java.io.*;
import java.util.Date;
import java.util.Scanner;

public class Server
{
    public Socket client;
    public ServerSocket server;
    public BufferedReader in;
    public OutputStream out;
    public String calc;
    public String ans;
    public int portNumber;

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
            //server = new ServerSocket(portNumber);
            client = server.accept();
            in = new BufferedReader(new InputStreamReader(client.getInputStream()));
            out = client.getOutputStream();
            
            serveReq();
            //sendError(405);
 
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
            
            // check for valid version (protocol):
            if (version.equals("HTTP/1.1"))
            {
                //check for valid request method:
                if (method.equals("GET"))
                {
                    if (uri.charAt(0) == '/' && (uri.length() == 2 || uri.length() == 1))
                    {
                        if (uri.length() == 1)
                        {
                            sendResponse(' ');
                        }
                        else
                        {
                            switch (uri.charAt(1))
                            {
                                case '0':
                                case '1':
                                case '2':
                                case '3':
                                case '4':
                                case '5':
                                case '6':
                                case '7':
                                case '8':
                                case '9':
                                case 'x':
                                case 'd':
                                case '+':
                                case '-':
                                case '=':
                                case 'C':
                                case 'p':
                                    sendResponse(uri.charAt(1));
                                    break;
                                
                                default:
                                    sendError(404);
                                    break;
                            }
                        }
                    }
                    else
                    {
                        sendError(404);
                    }
                }
                else if ( method.equals("POST") || method.equals("PUT") || method.equals("PATCH") || method.equals("DELETE") )
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

            splitter.close();
            splitter2.close();
        }
        catch (Exception e)
        {

        }
    }

    public void sendResponse(char href)
    {
        String response = "HTTP/1.1 200 OK\r\n";
        response += "Server: 0.0.0.0:8080\r\n";
        response += "Date: " + new Date() + "\r\n";
        response += "Content-Type: text/html\r\n";

        if (ans.equals("ERROR"))
        {
            ans = "0";
            calc = ans;
        }

        switch (href)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if (calc.equals("0"))
                {
                    calc = "";
                }
                calc += href;
                break;

            case 'd':
                if (calc.contains("x") || calc.contains("/") || calc.contains("+") || calc.contains("-"))
                {
                    doCalculation();
                }
                calc += '/';
                break;

            case 'x':
            case '+':
            case '-':
                if (calc.contains("x") || calc.contains("/") || calc.contains("+") || calc.contains("-"))
                {
                    doCalculation();
                }
                calc += href;
                break;

            case '=':
                doCalculation();
                break;

            case 'C':
            case ' ':
                calc = "0";
                ans = "0";
                break;

            case 'p':
                calc += '.';
        }
        
        String page = "<!DOCTYPE html><html lang='en'> <head> <meta charset='utf-8'> <title>Calculator</title> <style>.right{text-align: right; padding-right: 5%;}.center{text-align: center;}.dig{width: 100px;}table{height: 50%; position: absolute; top: 50%; left: 50%; transform: translate(-50%, -50%);}*{font-size: 30px;}a{text-decoration: none;}</style> </head> <body> <table border='1'> <tr> <td colspan='4' class='right'>" + calc + "</td></tr><tr> <td colspan='1' class='center'><a href='C'>CE</td><td colspan='3' class='right'>" + ans + "</td></tr><tr> <td class='center dig'><a href='7'>7</a></td><td class='center dig'><a href='8'>8</a></td><td class='center dig'><a href='9'>9</a></td><td class='center dig'><a href='d'>/</a></td></tr><tr> <td class='center dig'><a href='4'>4</a></td><td class='center dig'><a href='5'>5</a></td><td class='center dig'><a href='6'>6</a></td><td class='center dig'><a href='x'>x</a></td></tr><tr> <td class='center dig'><a href='1'>1</a></td><td class='center dig'><a href='2'>2</a></td><td class='center dig'><a href='3'>3</a></td><td class='center dig'><a href='-'>-</a></td></tr><tr> <td class='center'><a href='0'>0</a></td><td class='center'><a href='p'>.</a></td><td class='center dig'><a href='='>=</a></td><td class='center'><a href='+'>+</a></td></tr></table> </body></html>";

        response += "Content-length: " + page.length() + "\r\n";
        response += "\r\n\r\n";      
        response += page;

        try
        {
            out.write(response.getBytes());
            out.flush();
        }
        catch (IOException i)
        {
            System.out.println(i);
        }
    }

    public void doCalculation()
    {
        if (calc.contains("x") || calc.contains("/") || calc.contains("+") || calc.contains("-"))
        {
            if (calc.contains("x"))
            {
                double n1 = Double.parseDouble(calc.substring(0, calc.indexOf("x")));
                double n2 = Double.parseDouble(calc.substring(calc.indexOf("x")+1));
                ans = Double.toString(n1 * n2);
                calc = ans;
            }
            else if (calc.contains("/"))
            {
                double n1 = Double.parseDouble(calc.substring(0, calc.indexOf("/")));
                double n2 = Double.parseDouble(calc.substring(calc.indexOf("/")+1));

                if(n2 == 0)
                {
                    ans = "ERROR";
                }
                else
                {
                    ans = Double.toString(n1 / n2);
                }
                calc = ans;
            }
            else if (calc.contains("+"))
            {
                double n1 = Double.parseDouble(calc.substring(0, calc.indexOf("+")));
                double n2 = Double.parseDouble(calc.substring(calc.indexOf("+")+1));
                ans = Double.toString(n1 + n2);
                calc = ans;
            }
            else if (calc.contains("-"))
            {
                double n1 = Double.parseDouble(calc.substring(0, calc.indexOf("-")));
                double n2 = Double.parseDouble(calc.substring(calc.indexOf("-")+1));
                ans = Double.toString(n1 - n2);
                calc = ans;
            }
        }
        else
        {
            ans = calc;
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