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

    private JButton btnGetAllStudents;
    private JButton btnGetByStudentNo;
    private JButton btnAddStudent;
    private JButton btnDeleteStudent;

    private JButton btnGetAllPracticals;
    private JButton btnGetByPracticalsNo;
    private JButton btnAddPracticals;
    private JButton btnDeletePracticals;

    private JButton btnAddPracToStudent;
    private JButton btnRemovePracFromStudent;

    private static JTable studentTable;
    private static JTable practicalTable;

    private JLabel lblPracticalTable;
    private JLabel lblStudentTable;

    private JScrollPane studentPane;
    private JScrollPane practicalPane;

    private static JFrame addStudentFrame;
    private static JFrame addPracticalFrame;

    private static String oldStudentNumber;

    private static boolean onloadpracticals = true;
    private static boolean onloadstudents = true;
    
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
        frame.setSize(new Dimension(765, 516));
        frame.setResizable(false);

        Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
        frame.setLocation(dim.width/2-this.getSize().width/2 - (720/2), dim.height/2-this.getSize().height/2 - (516/2));

        //construct studentTable
        DefaultTableModel studentModel = new javax.swing.table.DefaultTableModel();
        studentTable = new JTable(studentModel);
        studentTable.setAutoResizeMode(JTable.AUTO_RESIZE_ALL_COLUMNS);
        studentPane = new JScrollPane(studentTable);
        studentTable.setEnabled(true);
        studentTable.setFocusable(false);
        studentTable.setRowSelectionAllowed(true);
        studentModel.addColumn("id");
        studentModel.addColumn("Name");
        studentModel.addColumn("Surname");
        studentModel.addColumn("Degree");
        studentModel.addColumn("Student Number");

        //construct practicalTable:
        DefaultTableModel practicalModal = new javax.swing.table.DefaultTableModel();
        practicalTable = new JTable(practicalModal);
        practicalTable.setAutoResizeMode(JTable.AUTO_RESIZE_ALL_COLUMNS);
        practicalPane = new JScrollPane(practicalTable);
        practicalTable.setEnabled(true);
        practicalTable.setFocusable(false);
        practicalTable.setRowSelectionAllowed(true);
        practicalModal.addColumn("id");
        practicalModal.addColumn("Name");

        //buttons for Students:
        btnGetAllStudents = new JButton("Get All Students");
        btnGetAllStudents.addActionListener(listener -> {
            getAllStudents();
        });

        btnGetByStudentNo = new JButton("Search Student Number");
        btnGetByStudentNo.addActionListener(listener -> {
            getByStudentNoClick();
        });

        btnAddStudent = new JButton("Add Student");
        btnAddStudent.addActionListener(listener -> {
            addStudentClick();
        });

        btnDeleteStudent = new JButton("Delete Student");
        btnDeleteStudent.addActionListener(listener -> {
            deleteStudentClick();
        });

        //buttons for Practical:
        btnGetAllPracticals = new JButton("Get All Practicals");
        btnGetAllPracticals.addActionListener(listener -> {
            getAllPracticals();
        });

        btnGetByPracticalsNo = new JButton("Search Student Number");
        btnGetByPracticalsNo.addActionListener(listener -> {
            getByPracticalNameClick();
        });

        btnAddPracticals = new JButton("Add Practical");
        btnAddPracticals.addActionListener(listener -> {
            addPracticalClick();
        });

        btnDeletePracticals = new JButton("Delete Practical");
        btnDeletePracticals.addActionListener(listener -> {
            deletePractialClick();
        });

        btnAddPracToStudent = new JButton("Add Practical to Student");
        btnAddPracToStudent.addActionListener(listener -> {
            addPracToStudentClick();
        });

        btnRemovePracFromStudent = new JButton("Remove Practical from Student");
        btnRemovePracFromStudent.addActionListener(listener -> {
            removePracFromStudentClick();
        });

        //add components
        frame.add(btnGetAllStudents);
        frame.add(btnGetByStudentNo);
        frame.add(btnAddStudent);
        frame.add(btnDeleteStudent);
        frame.add(studentPane);
        frame.add(practicalPane);
        frame.add(btnAddPracToStudent);

        lblPracticalTable = new JLabel("Practicals:");
        lblStudentTable = new JLabel("Students:");
        frame.add(lblPracticalTable);
        frame.add(lblStudentTable);
        frame.add(btnAddPracticals);
        frame.add(btnDeletePracticals);
        frame.add(btnGetAllPracticals);

        btnAddPracToStudent.setBounds(20, 50, 175, 25);
        studentTable.setBounds(0, 120, 500, 350);
        studentPane.setBounds(20, 120, 500, 350);
        practicalTable.setBounds(540, 120, 200, 350);
        practicalPane.setBounds(540, 120, 200, 350);
        btnGetByStudentNo.setBounds(20, 15, 175, 25);
        btnAddStudent.setBounds(390, 50, 130, 25);
        btnDeleteStudent.setBounds(390, 85, 130, 25);
        btnGetAllStudents.setBounds(345, 15, 175, 25);
        btnAddPracticals.setBounds(610, 50, 130, 25);
        btnDeletePracticals.setBounds(610, 85, 130, 25);
        btnGetAllPracticals.setBounds(565, 15, 175, 25);

        //fetch all data from db:
        getAllStudents();
        getAllPracticals();

    }

    public void removePracFromStudentClick() {
        int row = studentTable.getSelectedRow();

        //check if row is selected:
        if (row == -1) {
            JOptionPane.showMessageDialog(null, "Select a student before trying to remove a practical.");
            return;
        }
    }

    public void addPracToStudentClick() {
        int row = studentTable.getSelectedRow();

        //check if row is selected:
        if (row == -1) {
            JOptionPane.showMessageDialog(null, "Select a student before trying to add a practical.");
            return;
        }

        String targetPractical = JOptionPane.showInputDialog("Enter the name of the practical you want to add to the student.");

        //check if input is empty:
        if (targetPractical == null || targetPractical.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Please enter a practical name.");
            return;
        }

        //check if practical exists:
        if (!checkByPracticalName(targetPractical)) {
            JOptionPane.showMessageDialog(null, "Practical does not exist.");
            return;
        }

        //fetch practical:
        em.getTransaction().begin();
        Practical practical = em.createQuery("SELECT p FROM Practical p WHERE p.name = :name", Practical.class)
                .setParameter("name", targetPractical)
                .getSingleResult();
        em.getTransaction().commit();

        //fetch student:
        int id = Integer.parseInt(studentTable.getValueAt(row, 0).toString());
        em.getTransaction().begin();
        Student student = em.find(Student.class, id);
        System.out.println(student.getPracticals());
        if (student.getPracticals() != null) {
            if (student.getPracticals().contains(practical)) {
                JOptionPane.showMessageDialog(null, "Student already has this practial.");
                em.getTransaction().commit();
                return;
            }
        }
            
        student.addPractical(practical);
        em.getTransaction().commit();


        //add student to practical:
        em.getTransaction().begin();
        practical.addStudent(student);
        em.merge(practical);
        em.getTransaction().commit();

        JOptionPane.showMessageDialog(null, "Practical has been added to student.", "Success", JOptionPane.INFORMATION_MESSAGE);       
        
        getAllPracticals();
        getAllStudents();
    }

    public static void getAllPracticals() {
        DefaultTableModel model = (DefaultTableModel) practicalTable.getModel();
        model.setRowCount(0);
        //fetch studentTable from db:
        TypedQuery<Practical> query = em.createQuery("SELECT p FROM Practical p", Practical.class);
        List<Practical> results = query.getResultList();
        if (query.getResultList().size() != 0) {
            for (Practical practical : results) {
                //populate the studentTable here
                model.addRow(new Object[] {practical.getId(), practical.getName()});
            }
        } else {
            if (!onloadpracticals)
                JOptionPane.showMessageDialog(null, "No Practicals to display.");
        }
        onloadpracticals = false;
    }

    public void getByPracticalNameClick() {
        String target = JOptionPane.showInputDialog("Enter name of practical to search for:");
        getByPracticalName(target);
    }

    public void getByPracticalName(String target) {

    }

    public void addPracticalClick() {
        MainFrame.addPracticalFrame = new JFrame ("Add Practical");
        addPracticalFrame.getContentPane().add(new AddPractical());
        addPracticalFrame.pack();
        addPracticalFrame.setVisible (true);
        Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
        addPracticalFrame.setLocation(dim.width/2-280/2, dim.height/2-299/2);
    }

    public static void addPractical(Practical practical) {
        //check if number exists
        if (checkByPracticalName(practical.getName())) {
            throw new IllegalArgumentException("A practical with this name already exists");
        }
        //add to db
        em.getTransaction().begin();
        em.persist(practical);
        
        em.getTransaction().commit();
        getAllPracticals();
    }

    public void deletePractialClick() {

        int row = practicalTable.getSelectedRow();

        //check if row is selected:
        if (row == -1) {
            JOptionPane.showMessageDialog(null, "Click on a practical before trying to delete");
            return;
        }

        //confirm delete:
        int input = JOptionPane.showConfirmDialog(null, "Do you want to delete \"" + practicalTable.getValueAt(row, 1).toString() + "\"", "Select an Option...",
				JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.ERROR_MESSAGE);

        if (input != 0)
            return;
            
        //get student id:
        int id = Integer.parseInt(practicalTable.getValueAt(row, 0).toString());
        em.getTransaction().begin();
        Practical practical = em.find(Practical.class, id);
        em.getTransaction().commit();
        
        //remove from students:
        if (practical.getStudents() != null) {
            for (Student student : practical.getStudents()) {
                em.getTransaction().begin();
                student.removePractical(practical);
                em.getTransaction().commit();
            }
        }
        
        em.getTransaction().begin();
        em.remove(practical);
        em.getTransaction().commit();
        
        getAllPracticals();

    }

    //close database connection:
    private void closeDBConnection() {
        em.close();
        emf.close();
    }
    
    //get all:
    public static void getAllStudents() {
        DefaultTableModel model = (DefaultTableModel) studentTable.getModel();
        model.setRowCount(0);
        //fetch studentTable from db:
        TypedQuery<Student> query = em.createQuery("SELECT s FROM Student s", Student.class);
        List<Student> results = query.getResultList();
        if (query.getResultList().size() != 0) {
            for (Student student : results) {
                //populate the studentTable here
                model.addRow(new Object[] {student.getId(), student.getName(), student.getSurname(), student.getDegree(), student.getStudentNumber()});
            }
        } else {
            if (!onloadstudents)
                JOptionPane.showMessageDialog(null, "No Students to display.");
        }
        onloadstudents = false;
    }

    //get by student number:
    public static void getByStudentNoClick() {
        String target = JOptionPane.showInputDialog("Enter student number to search for:");
        getByStudentNumber(target);
    }

    public static void getByStudentNumber(String studentNo) {
        //fetch student:
        em.getTransaction().begin();
        TypedQuery<Student> queryStudent = em.createQuery("SELECT FROM Student s WHERE s.studentNumber = \"" + studentNo + "\"", Student.class);
        em.getTransaction().commit();

        if (queryStudent.getResultList().size() == 0) {
            JOptionPane.showMessageDialog(null, "No student with matching student number was found.");
            return;
        }

        Student s = queryStudent.getResultList().get(0);
        //populate studentTable:
        DefaultTableModel modelStudent = (DefaultTableModel) studentTable.getModel();
        modelStudent.setRowCount(0);
        modelStudent.addRow(new Object[] {s.getId(), s.getName(), s.getSurname(), s.getDegree(), s.getStudentNumber()});

        //join to pracs:
        DefaultTableModel model = (DefaultTableModel) practicalTable.getModel();
        model.setRowCount(0);

        if (s.getPracticals() == null) {
            return;
        }
        if (s.getPracticals().size() == 0) {
            return;
        }
        //fetch studentTable from db:
        for (Practical practicals : s.getPracticals()) {
            //populate the studentTable here
            model.addRow(new Object[] {practicals.getId(), practicals.getName()});
        }
    }

    //add student:
    public static void addStudentClick() {
        MainFrame.addStudentFrame = new JFrame ("Add Student");
        addStudentFrame.getContentPane().add (new AddStudent());
        addStudentFrame.pack();
        addStudentFrame.setVisible (true);
        Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
        addStudentFrame.setLocation(dim.width/2-280/2, dim.height/2-299/2);
    }

    public static void closeAddStudent() {
        addStudentFrame.dispose();
    }

    public static void closeAddPractical() {
        addPracticalFrame.dispose();
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
        getAllStudents();
    }

    //delete student:
    public static void deleteStudentClick() {

        int row = studentTable.getSelectedRow();

        //check if row is selected:
        if (row == -1) {
            JOptionPane.showMessageDialog(null, "Click on a student before trying to delete");
            return;
        }

        //confirm delete:
        int input = JOptionPane.showConfirmDialog(null, "Do you want to delete \"" + studentTable.getValueAt(row, 1).toString() + " " + studentTable.getValueAt(row, 2).toString() + "\"", "Select an Option...",
				JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.ERROR_MESSAGE);

        if (input != 0)
            return;

        //get student id:
        int id = Integer.parseInt(studentTable.getValueAt(row, 0).toString());
        em.getTransaction().begin();
        Student student = em.find(Student.class, id);
        em.remove(student);
        em.getTransaction().commit();

        getAllStudents();

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

    public static boolean checkByPracticalName(String practicalName) {
        em.getTransaction().begin();
        TypedQuery<Practical> query = em.createQuery("SELECT FROM Practical p WHERE p.name = \"" + practicalName + "\"", Practical.class);
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
        if (studentNo.equals(oldStudentNumber))
            return false;

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
