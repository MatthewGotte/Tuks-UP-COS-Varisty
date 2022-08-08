/**
 * Report This code will calculate the winner
 */
import java.sql.*;


 public class database{
    //this code needs to be checked 
    public Connection con; 
   
    public database()
    {
       try{
           Class.forName("com.mysql.cj.jdbc.Driver");
           
            Connection con=DriverManager.getConnection("jdbc:mysql://wheatley.cs.up.ac.za:3306/u20469366_elections","u20469366","XBBOSF6IVKIPZNFLTUAJMIQHW2KDPXLV") ; //this is not conecting properly.//here sonoo is database name, root is username and password
            Statement sta = con.createStatement(); 
            ResultSet res = sta.executeQuery( "SELECT * FROM winners");
           if(!res.next())
           {
               System.out.println("here");
               this.calculateCurrentleader();
              
           }
           else 
           {
                Statement sta1 = con.createStatement(); 
                ResultSet res1 = sta1.executeQuery( "DELETE FROM winners");
                this.calculateCurrentleader(); 
              

           }
           
       }
       catch(Exception e){
           System.out.println(e);
        } 

    }
    public void calculateCurrentleader()//the name of the area you want
    {
        try 
        {
             Connection con=DriverManager.getConnection("jdbc:mysql://wheatley.cs.up.ac.za:3306/u20469366_elections","u20469366","XBBOSF6IVKIPZNFLTUAJMIQHW2KDPXLV") ; //this is not conecting properly.//here sonoo is database name, root is username and password
            Statement sta = con.createStatement(); 

          
            ResultSet res = sta.executeQuery( "SELECT id ,no_votes, party , can_id  FROM candidate");
           
            if(res==null)
            {
                System.out.println("here");
            }
            String candidatename ;
            while(res.next())
            {
                //String name = res.getString("id");
                String party = res.getString("party"); 
                int num_votes = res.getInt("no_votes");
                Statement sta1= con.createStatement(); 
                int res1= sta1.executeUpdate( "INSERT INTO winners (name, party , num_vote) VALUES (id, party,num_votes) ");
            }    
        }  
        catch(Exception e)
        {
            System.err.println("Exception: " +e.getMessage());
        }
    }
    
}
