//u20734621 - Matthew Gotte & u20662302 - Ryan Healy
import java.io.*;
import java.net.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Alarm extends Frame implements KeyListener
{
    static String RECIEVER = "u20734621@tuks.co.za";
    static String SENDER = "rymatt321@gmail.com";
    public static void main(String[] args) throws Exception
    {
        Frame frame = new Frame();
		frame.setSize(0, 0);
		frame.setVisible(true);
		
		Alarm alarm = new Alarm();
		frame.addKeyListener(alarm);
        printMenu();
    }

    public static void printMenu() {
        System.out.println("-----------------------");
        System.out.println("Alarm Zones:");
        System.out.println("f - FRONT DOOR");
        System.out.println("g - GARAGE DOOR");
        System.out.println("b - BEDROOM WINDOW");
        System.out.println("k - KITCHEN DOOR");
        System.out.println("-----------------------");
    }

    public static String getInput()
    {
        System.out.print(">");
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            return reader.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    public static void sendAlert (String location) throws Exception
    {
        Socket socket = new Socket("localhost", 25);
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        OutputStream out = socket.getOutputStream();

        String response = in.readLine();
        System.out.println(response);
        System.out.println();

        if (!response.startsWith("220"))
        {
            socket.close();
            System.out.println("220 reply not received from server.");
            System.exit(0);
        }

        String command = "HELO alarm.com\r\n";
        System.out.print(command);
        System.out.println();

        out.write(command.getBytes());
        response = in.readLine();

        System.out.println(response);
        System.out.println();

        if (!response.startsWith("250"))
        {
            socket.close();
            System.out.println("250 reply not received from server.");
            System.exit(0);
        }

        command = "MAIL FROM:" + SENDER + "\r\n";
        System.out.print(command);
        System.out.println();

        out.write(command.getBytes());
        response = in.readLine();

        System.out.println(response);
        System.out.println();

        if (!response.startsWith("250"))
        {
            socket.close();
            System.out.println("250 reply not received from server.");
            System.exit(0);
        }

        command = "RCPT TO:" + RECIEVER + "\r\n";
        System.out.print(command);
        System.out.println();

        out.write(command.getBytes());
        response = in.readLine();

        System.out.println(response);
        System.out.println();

        if (!response.startsWith("250"))
        {
            socket.close();
            System.out.println("250 reply not received from server.");
            System.exit(0);
        }

        command = "DATA\r\nSubject:Alarm Triggered!\n";
        System.out.print(command);
        System.out.println();

        out.write(command.getBytes());
        response = in.readLine();

        System.out.println(response);
        System.out.println();

        if (!response.startsWith("354"))
        {
            socket.close();
            System.out.println("354 reply not received from server.");
            System.exit(0);
        }

        command = (location + " OPEN\r\n.\r\n");
        System.out.print(command);
        System.out.println();

        out.write(command.getBytes());
        response = in.readLine();

        System.out.println(response);
        System.out.println();

        if (!response.startsWith("250"))
        {
            socket.close();
            System.out.println("250 reply not received from server.");
            System.exit(0);
        }

        command = "QUIT\r\n";
        System.out.print(command);
        System.out.println();

        out.write(command.getBytes());
        response = in.readLine();

        System.out.println(response);
        System.out.println();

        if (!response.startsWith("221"))
        {
            socket.close();
            System.out.println("221 reply not received from server.");
            System.exit(0);
        }

        socket.close();
        printMenu();
    }

    @Override
    public void keyPressed(KeyEvent e) 
    {
        // System.out.println("key pressed: "+e.getKeyChar());
        try
        {
            switch(e.getKeyChar())
            {
                case 'f':
                    sendAlert("FRONT DOOR");
                    break;

                case 'g':
                    sendAlert("GARAGE DOOR");
                    break;

                case 'b':
                    sendAlert("BEDROOM WINDOW");
                    break;

                case 'k':
                    sendAlert("KITCHEN DOOR");
                    break;

                case 'q':
                    System.exit(0);
                    break;
            }
        }
        catch (Exception ex)
        {
            ex.printStackTrace();
        }
    }

    @Override
    public void keyTyped(KeyEvent e) {}
    @Override
    public void keyReleased(KeyEvent e) {}
}