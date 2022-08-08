import javax.persistence.Entity;
import java.io.Serializable;
import javax.persistence.*;

@Entity
public class Student {
    private static final long serialVersionUID = 1L;

    @Id @GeneratedValue
    private long id;
    private String name;
    private String surname;
    private String degree;
    private String studentNumber;

    public Student() {
    }

    public Student(String name, String surname, String degree, String studentNumber) {
        this.name = name;
        this.surname = surname;
        this.degree = degree;
        this.studentNumber = studentNumber;
    }

    public long getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public String getDegree() {
        return degree;
    }

    public void setDegree(String degree) {
        this.degree = degree;
    }

    public String getStudentNumber() {
        return studentNumber;
    }

    public void setStudentNumber(String studentNumber) {
        this.studentNumber = studentNumber;
    }

    @Override
    public String toString() {
        return name + " " + surname + "\t" + degree + "\t" + studentNumber;
    }

    public boolean isValid() {
        return name.length() != 0 && surname.length() != 0 && degree.length() != 0 && studentNumber.length() != 0;
    }

}
