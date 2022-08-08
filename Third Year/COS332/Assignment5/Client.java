//u20734621 - Matthew Gotte & u20662302 - Ryan Healy
import java.io.*;
import java.net.*;
import java.util.*;
import javax.naming.*;
import javax.naming.directory.*;

public class Client 
{

    // s.connect(asdf);

    //     //SocketAddress k = new SocketAddress();
    //     BufferedOutputStream o = new BufferedOutputStream(s.getOutputStream());
    //     //DataOutputStream o = new DataOutputStream(s.getOutputStream());
    //     BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));
    //     // Scanner in = new Scanner(new InputStreamReader(s.getInputStream()));
    //     // Scanner inputScanner = new Scanner(System.in);
 
    //     // String input = inputScanner.nextLine();
    
    public static String search(String name) throws Exception
    {
        Hashtable environment = new Hashtable();

        environment.put(Context.PROVIDER_URL, "ldap://192.168.179.130:389");
        environment.put(Context.INITIAL_CONTEXT_FACTORY, "com.sun.jndi.ldap.LdapCtxFactory");

        DirContext ldapServer = new InitialDirContext(environment);

        Attributes attrs = new BasicAttributes();
        attrs.put(new BasicAttribute("cn"));
        String[] ret = {"telephonenumber"};
        NamingEnumeration res = ldapServer.search("ou=contacts,dc=example,dc=com", ("cn="+name), new SearchControls()); 

        if(res.hasMoreElements())
        {
            String vibe = String.valueOf(res.nextElement());
            vibe = vibe.substring(vibe.indexOf("telephonenumber=telephoneNumber: ")+33, vibe.indexOf("telephonenumber=telephoneNumber")+43);
            return vibe;
        }

        return null;
    }
    
    public static void start() {
        boolean flag = true;
        while (flag) {
            printMenu();
            String choice = getInput();
            switch (choice) {
                case "1":
                    System.out.print("Name to search for: ");
                    String searchName = getInput();
                    try {
                        // System.out.println(search(searchName) + "\n");
                        String output = search(searchName);
                        if (output != null) {
                            System.out.println("\n=== CONTACT FOUND ===");
                            System.out.println("Name: " + searchName);
                            System.out.println("Tel No.: " + output);
                            System.out.println("=====================\n");
                        } else {
                            System.out.println("This name does not exist in the database \n");
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    break;
                case "2":
                    flag = false;
                    break;
                default:
                    System.out.println("Invalid choice.\n");
            }
        }
    }

    public static String getInput() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            return reader.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    public static void printMenu() {
        System.out.println("Choose an option:");
        System.out.println("1. Search by a name");
        System.out.println("2. Exit");
        System.out.print("Input: ");
    }

    public static void main(String[] args) throws Exception 
    {
        start();
        

        /*Socket s = new Socket();
        InetAddress asdf = 192.168.179.130;

        s.connect(asdf);

        //SocketAddress k = new SocketAddress();
        BufferedOutputStream o = new BufferedOutputStream(s.getOutputStream());
        //DataOutputStream o = new DataOutputStream(s.getOutputStream());
        BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));
        // Scanner in = new Scanner(new InputStreamReader(s.getInputStream()));
        // Scanner inputScanner = new Scanner(System.in);
 
        // String input = inputScanner.nextLine();

        //String t = "ldapsearch -x -b 'cn=Joe Soap,ou=contacts,dc=example,dc=com' -H ldap://192.168.179.130 telephoneNumber";
        String t = "ldapsearch -x -b 'cn=Joe Soap,ou=contacts,dc=example,dc=com' telephoneNumber\n";
        //String t = "ldapsearch -b 'ou=contacts' -s sub -v 'cn=Joe Soap'";
        //String t = "ldapsearch -x";
        // o.write(t.getBytes(), 0, t.getBytes().length);
        o.write(t.getBytes());
        o.flush();
        System.out.println("here1");
        // this gets stuck for some reason, not sure why
        // while(in.hasNext())
        // {
        //     System.out.println("here2");
        //     System.out.println(in.next());
        //     System.out.println("here3");
        // }
        // System.out.println("here4");

        while (in.ready())
        {
            System.out.println("here2");
            System.out.println(in.read());
            System.out.println("here3");   
        }
        System.out.println("here4");

        // t = "0\n";
        // o.write(t.getBytes(), 0, t.getBytes().length);
        // o.flush();

        o.close();
        in.close();
        // inputScanner.close();
        s.close();*/
    }
}