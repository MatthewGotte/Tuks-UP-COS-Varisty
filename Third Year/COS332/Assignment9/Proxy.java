// u20734621 - Matthew Gotte, u20662302 - Ryan Healy
import java.net.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.annotation.processing.SupportedOptions;
 
public class Proxy
{
    public String telnetServerAddress = "192.168.88.238";
    public int telnetPort = 23;
    public int proxyPort = 8080;

    public ServerSocket proxyServer = null;
    public Socket proxyClient;
    
    // public BufferedReader proxyIn;
    // public BufferedWriter proxyOut;
    public InputStream proxyIn;
    public OutputStream proxyOut;

    public Socket telnetServer;
    public InputStream tnIn;
    public OutputStream tnOut;

    public int inRead;
    public boolean debug = false;

    public Proxy(boolean b)
    {
        debug = b;
    }

    public boolean validateConnectionString(String con) 
    {
        // Pattern p = Pattern.compile("^([0-9]{1,3}\\){3}([0-9]{1,3}) [0-9]{0,5}$", Pattern.LITERAL);
        String regex = "^([0-9]{1,3}\\.){3}([0-9]{1,3}) [0-9]{0,5}$";

        // Matcher matcher = p.matcher(con);
        // if (matcher.find()) 
        if(Pattern.matches(regex, con))
        {
            int port = getPort(con);
            return (port >= 0 && port <= 65535);
        }
        System.out.println("failed regex");
        return false;
    }

    public String getIP(String con) 
    {
        Scanner s = new Scanner(con).useDelimiter(" ");
        
        return s.next();
    }

    public int getPort(String con) 
    {
        Scanner s = new Scanner(con).useDelimiter(" ");
        
        s.next();
        return Integer.parseInt(s.next());
    }

    public void runProxy()
    {
        try
        {
            proxyServer = new ServerSocket(proxyPort);
            //System.out.println("Server Started\nWaiting for client connection...");
 
            proxyClient = proxyServer.accept();
            //System.out.println("Client connected");

            // proxyIn = new BufferedReader(new InputStreamReader(proxyClient.getInputStream()));
            // proxyOut = new BufferedWriter(new OutputStreamWriter(proxyClient.getOutputStream()));
            proxyIn = proxyClient.getInputStream();
            proxyOut = proxyClient.getOutputStream();

            boolean valid = true;
            String s = "";
            proxyOut.write("Enter the IP address and port to connect to\r\n".getBytes());

            do
            {
                s = "";
                if (!valid)
                {
                    proxyOut.write("Invalid address. Please try again\r\n".getBytes());
                }

                StringBuilder sb = new StringBuilder();

                while(!s.endsWith("\r\n"))
                {
                    sb.append((char)proxyIn.read());
                    s = sb.toString();
                }

                s = s.trim();
                valid = validateConnectionString(s);
            }
            while(!valid);
            displayInitial();
            
            this.telnetServerAddress = getIP(s);
            this.telnetPort = getPort(s);

            connectToTelnet();
            sendTelnetOptions();

            // proxyOut.write("> Proxy Connection Successful! Enter 0 to quit\r\n");
            // proxyOut.flush();
 
            String line = "";
            // displayInitial();
            ProxyThread px = new ProxyThread(tnIn, proxyOut);
            displayInitial();
            px.start();
            

            while (!line.equals("0\r\n"))
            {
                StringBuilder lineBuilder = new StringBuilder();
                line = "";
                while(!line.endsWith("\r\n"))
                {
                    int inInt = proxyIn.read();
                    lineBuilder.append((char)inInt);
                    line = lineBuilder.toString();
                    
                    System.out.print((char)inInt);
                    // System.out.print(inInt);

                    if (inInt != 13 && inInt != 10)
                    {
                        tnOut.write(inInt);
                        tnOut.flush();
                    }

                    // proxyOut.write(inInt);
                    // proxyOut.flush();

                    // figure out how to handle a backspace (int is 8)
                }                
                // check for ps here

                if(line.contains("ps"))
                {
                    int lineLength = line.length()-2;
                    System.out.println("line: " + line);
                    
                    line = line.trim();

                    // line = line.replaceAll("^/+", "");

                    System.out.println("line: " + line);
                    
                    int psIndex = line.indexOf("ps");
                    System.out.println(psIndex);
                    if (psIndex == 0)
                    {
                        if (line.length() == 2 || (line.length() == 3 && line.charAt(line.length()-1) == ';'))
                        {
                            for (int i = 0; i < lineLength; i++) 
                            {
                                tnOut.write(8);
                                proxyOut.write(8);
                            }
                            for (int i = 0; i < lineLength; i++) 
                            {
                                tnOut.write(32);
                                proxyOut.write(32);
                            }
                            for (int i = 0; i < lineLength; i++) 
                            {
                                tnOut.write(8);
                                proxyOut.write(8);
                            }
                        }
                    }
                    else if (line.charAt(line.indexOf("ps"))-1 == ';' || (line.charAt(line.indexOf("ps"))-1 == '&' && line.charAt(line.indexOf("ps"))-2 == '&'))
                    {
                        
                    }
                }

                tnOut.write(13);
                tnOut.write(10);
                tnOut.flush();
            }
            //System.out.println("Closing connection");
 
            px.stop();
            proxyClient.close();
            proxyIn.close();
            proxyOut.close();
        }
        catch(Exception i)
        {
            //System.out.println(i);
            i.printStackTrace();
        }
    }

    public boolean connectToTelnet()
    {
        if (debug)
            System.out.println("Attempting connection...");

        try
        {    
            telnetServer = new Socket(telnetServerAddress, telnetPort);
            telnetServer.setKeepAlive(true);

            if (debug)
                System.out.println("Connected!");

            tnIn = telnetServer.getInputStream();
            tnOut = telnetServer.getOutputStream();
            // inRead = tnIn.read();
        }
        catch (Exception e)
        {
            e.printStackTrace();
            return false;
        }
        return true;
    }

    public void printInStream() throws Exception
    {
        inRead = tnIn.read();
        
        if (debug)
        {
            System.out.print("in: 255 ");
            while (inRead != 255)
            {
                System.out.print(inRead + " ");
                inRead = tnIn.read();
            }
            System.out.println("\r\n");
        }
        else
        {
            while (inRead != 255)
            {
                inRead = tnIn.read();
            }
        }
    }

    public void printInStreamRemaining() throws Exception
    {
        if (debug)
        {
            while(inRead != -1)
            {
                System.out.print(inRead + " ");
                inRead = tnIn.read();
            }
            System.out.println("Done.");
        }
        else
        {
            while(inRead != -1)
            {
                inRead = tnIn.read();
            }
        }
    }

    public void printInStreamRemainingChar() throws Exception
    {
        while(inRead != -1)
        {
            System.out.print((char)inRead);
            inRead = tnIn.read();
        }
        System.out.println("Done.");
    }

    public void displayInitial() throws Exception
    {
        proxyOut.write(27);
        proxyOut.write("[2J".getBytes());
        proxyOut.flush();
    }

    public void sendTelnetOptions() throws Exception
    {
        int ops[];
        int ops2[];

        // IAC WILL TERMINAL-TYPE 
        // printInStream();
        ops = new int[]{255, 251, 24};
        sendToTelnet(ops);
        printInStream();

        // IAC WILL TERMINAL-SPEED
        // printInStream();
        ops = new int[]{255, 251, 32};
        sendToTelnet(ops);
        printInStream();

        // IAC WILL X DISPLAY-LOCATION
        // printInStream();
        ops = new int[]{255, 251, 35};
        sendToTelnet(ops);
        printInStream();

        // IAC WILL NEW-ENVIRONMENT-OPTION
        // printInStream();
        ops = new int[]{255, 251, 39};
        sendToTelnet(ops);
        printInStream();

        // IAC SB TERMINAL-SPEED IS "1200,1200" IAC SE
        ops = new int[]{255, 250, 32, 0};
        ops2 = new int[]{255, 240};
        sendToTelnet(ops, "1200,1200", ops2);
        printInStream();
        printInStream();

        // IAC SB X-DISPLAY-LOCATION IS "192.168.88.249:0.0" IAC SE
        ops = new int[]{255, 250, 35, 0};
        ops2 = new int[]{255, 240};
        sendToTelnet(ops, "192.168.88.249:0.0", ops2);
        printInStream();
        printInStream();

        // IAC SB NEW-ENVIRON IS IAC SE
        ops = new int[]{255, 250, 39, 0, 255, 240};
        // ops2 = new int[]{255, 240};
        sendToTelnet(ops);
        printInStream();
        printInStream();

        // IAC SB TERMINAL-TYPE IS VT500-7 IAC SE
        ops = new int[]{255, 250, 24, 0};
        ops2 = new int[]{255, 240};
        sendToTelnet(ops, "VT500-7", ops2);
        printInStream();
        printInStream();

        // IAC DO SUPPRESS-GO-AHEAD
        ops = new int[]{255, 253, 3};
        sendToTelnet(ops);
        printInStream();

        // IAC WONT ECHO
        ops = new int[]{255, 252, 1};
        sendToTelnet(ops);
        printInStream();

        // IAC WILL NAWS
        ops = new int[]{255, 251, 31};
        sendToTelnet(ops);
        printInStream();

        // // IAC WILL STATUS
        // ops = new int[]{255, 251, 5};
        // sendToTelnet(ops);
        // printInStream();

        // IAC DONT STATUS
        ops = new int[]{255, 254, 5};
        sendToTelnet(ops);
        printInStream();

        // IAC WILL TOGGLE-FLOW-CONTROL
        ops = new int[]{255, 251, 33};
        sendToTelnet(ops);
        printInStream();

        // IAC DO ECHO
        ops = new int[]{255, 253, 1};
        sendToTelnet(ops);
        // printInStream();
        // tnIn.read();
        // tnIn.read();
        // tnIn.read();

        // // IAC DO ECHO
        // ops = new int[]{255, 253, 1};
        // sendToTelnet(ops);
        // printInStream();

        // // IAC WILL TRANSMIT-BINARY
        // ops = new int[]{255, 251, 0};
        // sendToTelnet(ops);
        // printInStream();

        // IAC WILL EXTEND-ASCII
        ops = new int[]{255, 251, 17};
        sendToTelnet(ops);
        // printInStream();
        // System.out.print(tnIn.read() + " ");
        // System.out.print(tnIn.read() + " ");
        // System.out.println(tnIn.read() + " ");
        tnIn.read();
        // tnIn.read();
        tnIn.read();
        // printInStreamRemainingChar();

        // tnOut.write("ryserver".getBytes());
        // tnOut.flush();
        // tnOut.write(13);
        // tnOut.write(10);
        // tnOut.flush();
        
        // printInStreamRemainingChar();

        // tnOut.write("hello".getBytes());
        // tnOut.flush();
        // tnOut.write(13);
        // tnOut.write(10);
        // tnOut.flush();

        displayInitial();
        // printInStreamRemainingChar();
    }

    public void sendToTelnet(int[] ops) throws Exception
    {
        if (debug)
            System.out.print("out: ");

        byte[] bytes = new byte[ops.length];

        for (int i = 0; i < ops.length; i++)
        {
            bytes[i] = (byte)ops[i];
            if (debug)
                System.out.print(ops[i] + " ");
        }

        tnOut.write(bytes);
        tnOut.flush();
        if (debug)
            System.out.println("");
    }

    public void sendToTelnet(int[] ops, String v, int[] ops2) throws Exception
    {
        if (debug)
            System.out.print("out: ");

        byte[] bytes = new byte[ops.length];
        byte[] bytes2 = new byte[ops.length];

        for (int i = 0; i < ops.length; i++)
        {
            bytes[i] = (byte)ops[i];
            if (debug)
                System.out.print(ops[i] + " ");
        }

        if (debug)
            System.out.print(v + " ");

        for (int i = 0; i < ops2.length; i++)
        {
            bytes2[i] = (byte)ops2[i];
            if (debug)
                System.out.print(ops2[i] + " ");
        }

        tnOut.write(bytes);
        tnOut.write(v.getBytes());
        tnOut.write(bytes2);
        tnOut.flush();

        if (debug)
            System.out.println("");
    }

    public static void main(String[] args) 
    {
        try
        {
            Proxy proxy = new Proxy(false);
            // Proxy proxy = new Proxy(false, address, port);

            // proxy.connectToTelnet();
            // proxy.printInStream();
            // proxy.sendTelnetOptions();

            // System.out.println("Remaining: ");
            // proxy.printInStreamRemaining();
            // proxy.printInStreamRemainingChar();

            // proxy.temp();
            // temp();
            proxy.runProxy();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }
}
