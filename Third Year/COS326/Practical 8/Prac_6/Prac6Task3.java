import java.net.UnknownHostException;
import java.util.Set;

import com.mongodb.BasicDBList;
import com.mongodb.BasicDBObject;
import com.mongodb.DB;
import com.mongodb.DBCollection;
import com.mongodb.DBCursor;
import com.mongodb.DBObject;
import com.mongodb.MongoClient;

public class Prac6Task3 {

	
    public static void main(String[] args) throws UnknownHostException {
        // TODO code application logic here       
        MongoClient mongoClient = new MongoClient("localhost", 27017);     
        DB db = mongoClient.getDB("prac6db");
        DBCollection facebookCollection = db.getCollection("facebook");
        

        Set<String> collectionNames = db.getCollectionNames();
        

         System.out.println("All collection names");
         System.out.println();
         collectionNames.stream().forEach((collectionName) -> {
             System.out.println(collectionName);
        });
        System.out.println();

        BasicDBObject query = new BasicDBObject();
        
        DBCursor cursor = facebookCollection.find(query);
               
        int count = 0;
        while(cursor.hasNext()){
            DBObject object = cursor.next();
            BasicDBList data = (BasicDBList)object.get("data");
            BasicDBObject[] dataArray = data.toArray(new BasicDBObject[0]);
            
             System.out.println("All documents");
             System.out.println();
            for(BasicDBObject dbObject : dataArray){
                System.out.println(dbObject);
            }
            
            System.out.println();

            System.out.println("Number of messages in facebook collection");
            System.out.println();
            for(BasicDBObject dbObject : dataArray){
                System.out.println(dbObject.get("message"));              
                if(dbObject.get("message") != null){
                    count++;
                }
            }
        }
        System.out.println("Total messages: " + count);
        System.out.println();
        

        
        if(!db.collectionExists("messages")){
             db.createCollection("messages", new BasicDBObject());
        }
        
         DBCollection messagesCollection = db.getCollection("messages");  
            
            DBCursor cursor3 = facebookCollection.find(query);
            
            while (cursor3.hasNext()) { 
               DBObject object = cursor3.next();               
               
               BasicDBList data = (BasicDBList)object.get("data");               
                              
               BasicDBObject[] dataArray = data.toArray(new BasicDBObject[0]);
               
               for(BasicDBObject dbOgb : dataArray)
               {
                    BasicDBObject doc = new BasicDBObject("from", dbOgb.get("from")).append("message", dbOgb.get("message"));            
                    messagesCollection.insert(doc);        
               }
            }
        

           BasicDBObject query2 = new BasicDBObject();
           query2.put("message",java.util.regex.Pattern.compile("spring|September"));
           
           int messages = 0;
           DBCollection collection2 = db.getCollection("messages");
           
           DBCursor cursor4 = collection2.find(query2);
            
            while (cursor4.hasNext()) { 
                messages++;  
                cursor4.next();             
            }  
           System.out.println("Number of messages in messages collection");
           System.out.println("Number of messages: " + messages);           
           mongoClient.close();
    }    
}
