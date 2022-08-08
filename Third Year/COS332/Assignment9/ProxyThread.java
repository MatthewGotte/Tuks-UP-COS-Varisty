import java.net.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class ProxyThread extends Thread
{
    public InputStream tnIn;
    public OutputStream proxyOut;

    public ProxyThread(InputStream i, OutputStream o)
    {
        tnIn = i;
        proxyOut = o;
    }

    public void run()
    {
        try
        {
            int lastRead = -1;
            int currentRead = -1;
            while(true)
            {
                int inInt = tnIn.read();
                proxyOut.write(inInt);
                proxyOut.flush();

                lastRead = currentRead;
                currentRead = inInt;

                // just trust this
                if (currentRead == 64 && lastRead == 94)
                {
                    proxyOut.write(13);
                    proxyOut.flush();
                }
            }
        }
        catch(Exception e)
        {
            System.out.println("Thread Interrupted");
        }
    }
}
