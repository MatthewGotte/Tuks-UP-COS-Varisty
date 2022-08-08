import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class UpdateModal extends JPanel {

    private Student student;
    
    private JLabel lblName;
    private JLabel lblSurname;
    private JLabel lblDegree;
    private JLabel lblStudentNo;
    private JTextField txtName;
    private JTextField txtSurname;
    private JTextField txtDegree;
    private JTextField txtStudentNumber;
    private JButton btnSave;
    private JButton btnCancel;

    public UpdateModal(Student student) {

        this.student = student;

        //construct components
        lblName = new JLabel ("Name:");
        lblSurname = new JLabel ("Surname:");
        lblDegree = new JLabel ("Degree:");
        lblStudentNo = new JLabel ("Student Number:");
        txtName = new JTextField (5);
        txtName.setText(this.student.getName());
        txtSurname = new JTextField (5);
        txtSurname.setText(this.student.getSurname());
        txtDegree = new JTextField (5);
        txtDegree.setText(this.student.getDegree());
        txtStudentNumber = new JTextField (5);
        txtStudentNumber.setText(this.student.getStudentNumber());
        btnSave = new JButton ("Save");
        btnCancel = new JButton ("Cancel");

        //adjust size and set layout
        setPreferredSize (new Dimension (280, 299));
        setLayout (null);

        //add components
        add (lblName);
        add (lblSurname);
        add (lblDegree);
        add (lblStudentNo);
        add (txtName);
        add (txtSurname);
        add (txtDegree);
        add (txtStudentNumber);
        add (btnSave);
        add (btnCancel);

        //set component bounds (only needed by Absolute Positioning)
        lblName.setBounds (20, 10, 100, 25);
        lblSurname.setBounds (20, 65, 100, 25);
        lblDegree.setBounds (20, 120, 100, 25);
        lblStudentNo.setBounds (20, 175, 100, 25);
        txtName.setBounds (20, 30, 240, 25);
        txtSurname.setBounds (20, 85, 240, 25);
        txtDegree.setBounds (20, 140, 240, 25);
        txtStudentNumber.setBounds (20, 195, 240, 25);
        btnSave.setBounds (150, 245, 110, 25);
        btnCancel.setBounds (20, 245, 110, 25);

        btnCancel.addActionListener(listener -> {
            MainFrame.closeUpdate();
        });

        btnSave.addActionListener(listener -> {

            if (MainFrame.checkByStudentNumberForUpdate(txtStudentNumber.getText())) {
                JOptionPane.showMessageDialog(null, "Student with this student number already exists");
                return;
            }

            this.student.setName(txtName.getText());
            this.student.setSurname(txtSurname.getText());
            this.student.setDegree(txtDegree.getText());
            this.student.setStudentNumber(txtStudentNumber.getText());
            if (this.student.isValid()) {
                try {
                    MainFrame.updateStudent(this.student);
                    MainFrame.closeUpdate();
                    JOptionPane.showMessageDialog(null, "Student updated successfully");
                } catch (Exception e) {
                    JOptionPane.showMessageDialog(null, e.getMessage());
                }
            } else {
                JOptionPane.showMessageDialog(this, "All fields are required", "Error", JOptionPane.ERROR_MESSAGE);
            }
        });
    }
}
