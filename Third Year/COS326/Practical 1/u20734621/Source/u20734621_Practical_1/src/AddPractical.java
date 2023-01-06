import java.awt.*;
import javax.swing.*;

public class AddPractical extends JPanel {
    
    private Practical practical = new Practical();

    private JLabel lblName;
    private JTextField txtName;
    private JButton btnSave;
    private JButton btnCancel;

    public AddPractical() {
        //construct components
        lblName = new JLabel ("Name:");
        txtName = new JTextField (5);
        btnSave = new JButton ("Save");
        btnCancel = new JButton ("Cancel");

        //adjust size and set layout
        setPreferredSize (new Dimension (280, 299));
        setLayout (null);

        //add components
        add(lblName);
        add(txtName);
        add(btnSave);
        add(btnCancel);

        //set component bounds (only needed by Absolute Positioning)
        lblName.setBounds (20, 10, 100, 25);
        txtName.setBounds (20, 30, 240, 25);
        btnSave.setBounds (150, 85, 110, 25);
        btnCancel.setBounds (20, 85, 110, 25);

        btnCancel.addActionListener(listener -> {
            MainFrame.closeAddStudent();
        });

        btnSave.addActionListener(listener -> {
            practical.setName(txtName.getText());
            if (practical.isValid()) {
                try {
                    MainFrame.addPractical(practical);
                    MainFrame.closeAddPractical();
                    JOptionPane.showMessageDialog(null, "Practical created successfully");
                } catch (Exception e) {
                    JOptionPane.showMessageDialog(null, e.getMessage());
                }
            } else {
                JOptionPane.showMessageDialog(this, "Name is required", "Error", JOptionPane.ERROR_MESSAGE);
            }
        });
    }
}
