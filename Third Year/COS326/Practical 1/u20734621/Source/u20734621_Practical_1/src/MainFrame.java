import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import javax.persistence.*;
import java.util.List;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class MainFrame extends JFrame implements ActionListener {

    //database context
    private static EntityManagerFactory emf =
            Persistence.createEntityManagerFactory(
                "p2.odb");
    private static EntityManager em = emf.createEntityManager();

    private JButton btnGetAll;
    private JButton btnGetByStudentNo;
    private JButton btnAdd;
    private JButton btnDelete;
    private JButton btnUpdate;
    private static JTable table;
    private JScrollPane pane;

    private static JFrame addFrame;
    private static JFrame updateFrame;

    private static String oldStudentNumber;
    
    public MainFrame() {

        //building the JFrame
        JFrame frame = new JFrame("u20734621 - Practical 1");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                closeDBConnection();
            }
        });
        frame.pack();
        frame.setVisible(true);
        frame.setSize(new Dimension(720, 516));
        frame.setResizable(false);

        Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
        frame.setLocation(dim.width/2-this.getSize().width/2 - (720/2), dim.height/2-this.getSize().height/2 - (516/2));

        //construct table
        DefaultTableModel model = new DefaultTableModel();
        table = new JTable(model);
        table.setAutoResizeMode(JTable.AUTO_RESIZE_ALL_COLUMNS);
        pane = new JScrollPane(table);
        table.setEnabled(true);
        table.setFocusable(false);
        table.setRowSelectionAllowed(true);
        model.addColumn("id");
        model.addColumn("Name");
        model.addColumn("Surname");
        model.addColumn("Degree");
        model.addColumn("Student Number");

        // for (int i = 0; i < 50; i ++) {
        //     model.addRow(new Object [] {"1", "John", "Doe", "Bachelor", "123456789"});
        // }

        //construct components
        btnGetAll = new JButton("Get All");
        btnGetAll.addActionListener(listener -> {
            getAll();
        });

        btnGetByStudentNo = new JButton("Search Student Number");
        btnGetByStudentNo.addActionListener(listener -> {
            getByStudentNoClick();
        });

        btnAdd = new JButton("Add Student");
        btnAdd.addActionListener(listener -> {
            addStudentClick();
        });

        btnDelete = new JButton("Delete Student");
        btnDelete.addActionListener(listener -> {
            deleteStudentClick();
        });

        btnUpdate = new JButton("Update Student");
        btnUpdate.addActionListener(listener -> {
            updateStudentClick();
        });

        //add components
        frame.add(btnGetAll);
        frame.add(btnGetByStudentNo);
        frame.add(btnAdd);
        frame.add(btnDelete);
        frame.add(btnUpdate);
        frame.add(pane);

        int margin = 20;
        table.setBounds(0, 0, 671, 350);
        pane.setBounds(margin, 120, 671, 350);
        btnGetAll.setBounds(margin, 50, 100, 25);
        btnGetByStudentNo.setBounds(margin, margin, 175, 25);
        btnAdd.setBounds(560, 15, 130, 25);
        btnDelete.setBounds(560, 85, 130, 25);
        btnUpdate.setBounds(560, 50, 130, 25);

        //fetch all data from db:
        getAll();

    } 

    //close database connection:
    private void closeDBConnection() {
        em.close();
        emf.close();
    }
    
    //get all:
    public static void getAll() {
        DefaultTableModel model = (DefaultTableModel) table.getModel();
        model.setRowCount(0);
        //fetch table from db:
        TypedQuery<Student> query = em.createQuery("SELECT s FROM Student s", Student.class);
        List<Student> results = query.getResultList();
        for (Student student : results) {
            //populate the table here
            model.addRow(new Object[] {student.getId(), student.getName(), student.getSurname(), student.getDegree(), student.getStudentNumber()});
        }
    }

    //get by student number:
    public static void getByStudentNoClick() {
        String target = JOptionPane.showInputDialog("Enter student number to search for:");
        getByStudentNumber(target);
    }

    public static void getByStudentNumber(String studentNo) {
        em.getTransaction().begin();
        TypedQuery<Student> query = em.createQuery("SELECT FROM Student s WHERE s.studentNumber = \"" + studentNo + "\"", Student.class);
        em.getTransaction().commit();
        if (query.getResultList().size() != 0) {
            
            DefaultTableModel model = (DefaultTableModel) table.getModel();
            model.setRowCount(0);
            //fetch table from db:
            List<Student> results = query.getResultList();
            for (Student student : results) {
                //populate the table here
                model.addRow(new Object[] {student.getId(), student.getName(), student.getSurname(), student.getDegree(), student.getStudentNumber()});
            }

        } else {
            JOptionPane.showMessageDialog(null, "No results found", "No Result", JOptionPane.INFORMATION_MESSAGE);
        }
    }

    //add student:
    public static void addStudentClick() {
        MainFrame.addFrame = new JFrame ("Add Student");
        addFrame.getContentPane().add (new AddModal());
        addFrame.pack();
        addFrame.setVisible (true);
        Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
        addFrame.setLocation(dim.width/2-280/2, dim.height/2-299/2);
    }

    public static void closeAdd() {
        addFrame.dispose();
    }

    public static void addStudent(Student student) {
        //check if number exists
        if (checkByStudentNo(student.getStudentNumber())) {
            throw new IllegalArgumentException("A student with this student number already exists");
        }
        //add to db
        em.getTransaction().begin();
        em.persist(student);
        em.getTransaction().commit();
        getAll();
    }

    //delete student:
    public static void deleteStudentClick() {

        int row = table.getSelectedRow();

        //check if row is selected:
        if (row == -1) {
            JOptionPane.showMessageDialog(null, "Click on a row before trying to delete");
            return;
        }

        //confirm delete:
        int input = JOptionPane.showConfirmDialog(null, "Do you want to delete \"" + table.getValueAt(row, 1).toString() + " " + table.getValueAt(row, 2).toString() + "\"", "Select an Option...",
				JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.ERROR_MESSAGE);

        if (input != 0)
            return;

        //get student id:
        int id = Integer.parseInt(table.getValueAt(row, 0).toString());
        em.getTransaction().begin();
        Student student = em.find(Student.class, id);
        em.remove(student);
        em.getTransaction().commit();

        getAll();

    }

    //update student:
    public static void updateStudentClick() {

        int row = table.getSelectedRow();

        //check if row is selected:
        if (row == -1) {
            JOptionPane.showMessageDialog(null, "Click on a row before trying to update");
            return;
        }

        //get student:
        int id = Integer.parseInt(table.getValueAt(row, 0).toString());
        em.getTransaction().begin();
        Student student = em.find(Student.class, id);
        em.getTransaction().commit();

        //open update modal:
        MainFrame.updateFrame = new JFrame ("Update Student");
        updateFrame.getContentPane().add (new UpdateModal(student));
        oldStudentNumber = student.getStudentNumber();
        updateFrame.pack();
        updateFrame.setVisible (true);
        Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
        updateFrame.setLocation(dim.width/2-280/2, dim.height/2-299/2);

    }

    public static void closeUpdate() {
        updateFrame.dispose();
    }

    public static void updateStudent(Student student) {
        //update to db
        em.getTransaction().begin();
        em.merge(student);
        em.getTransaction().commit();
        getAll();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        // TODO Auto-generated method stub
    }

    public static boolean checkByStudentNo(String studentNo) {
        em.getTransaction().begin();
        TypedQuery<Student> query = em.createQuery("SELECT FROM Student s WHERE s.studentNumber = \"" + studentNo + "\"", Student.class);
        em.getTransaction().commit();
        if (query.getResultList().size() != 0) {
            return true;
        } else {
            return false;
        }
    }

    public static boolean checkByStudentNumberForUpdate(String studentNo) {
        //check if student number changed:
        System.out.println("check new = " + studentNo + " old = " + oldStudentNumber);
        
        //check if student number did not change:
        if (studentNo.equals(oldStudentNumber)) {
            System.out.println('a');
            return false;
        }

        //check for conflict with any other record
        em.getTransaction().begin();
        TypedQuery<Student> query = em.createQuery("SELECT FROM Student s WHERE s.studentNumber = \"" + studentNo + "\"", Student.class);
        em.getTransaction().commit();
        if (query.getResultList().size() != 0) {
            return true;
        } else {
            return false;
        }
    }

    public static boolean checkByStudentID(String studentID) {
        em.getTransaction().begin();
        TypedQuery<Student> query = em.createQuery("SELECT FROM Student s WHERE s.id = " + studentID, Student.class);
        em.getTransaction().commit();
        if (query.getResultList().size() != 0) {
            return true;
        } else {
            return false;
        }
    }

}
