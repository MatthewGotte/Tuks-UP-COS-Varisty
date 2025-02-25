import java.io.StringWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;

import org.w3c.dom.Document;
import org.w3c.dom.Element;

import java.io.PrintWriter;

public class Main{
    

   public static void main(String[] args)throws Exception {
     database db = new database();
    DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
    DocumentBuilder builder = factory.newDocumentBuilder();
    Document doc = builder.newDocument();
    Element results = doc.createElement("Results");
    doc.appendChild(results);

    Class.forName("com.mysql.cj.jdbc.Driver");
    Connection con = DriverManager
        .getConnection("jdbc:mysql://wheatley.cs.up.ac.za:3306/u20469366_elections","u20469366","XBBOSF6IVKIPZNFLTUAJMIQHW2KDPXLV");
    
    ResultSet rs = con.createStatement().executeQuery("select * from candidate");

    ResultSetMetaData rsmd = rs.getMetaData();
    int colCount = rsmd.getColumnCount();

    while (rs.next()) {
      Element row = doc.createElement("Row");
      results.appendChild(row);
      for (int i = 1; i <= colCount; i++) {
        String columnName = rsmd.getColumnName(i);
        Object value = rs.getObject(i);
        Element node = doc.createElement(columnName);
        if(value !=null)
        {
            node.appendChild(doc.createTextNode(value.toString()));
            row.appendChild(node);
            
        }

      }
    }
    DOMSource domSource = new DOMSource(doc);
    TransformerFactory tf = TransformerFactory.newInstance();
    Transformer transformer = tf.newTransformer();
    transformer.setOutputProperty(OutputKeys.OMIT_XML_DECLARATION, "yes");
    transformer.setOutputProperty(OutputKeys.METHOD, "xml");
    transformer.setOutputProperty(OutputKeys.ENCODING, "ISO-8859-1");
    StringWriter sw = new StringWriter();
    StreamResult sr = new StreamResult(sw);
    transformer.transform(domSource, sr);

    //System.out.println(sw.toString());
    //////
        PrintWriter outputfile = new PrintWriter("output.xml");
        outputfile.print("<?xml version='1.0'?>");
        outputfile.print(sw.toString());
        outputfile.close();
    //////
    con.close();
    rs.close();
  }
}
