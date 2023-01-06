import javax.persistence.Entity;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import javax.persistence.*;

@Entity
public class Practical {

    @Id @GeneratedValue
    private long practical_id;
    
    @OneToMany(targetEntity = Student.class)
    public List<Student> students;

    private String name;

    public Practical() {
    }

    public void addStudent(Student student) {
        if (students == null)
            students = new ArrayList<Student>();
        students.add(student);
    }

    public List<Student> getStudents() {
        return students;
    }

    public void removeStudent(Student student) {
        students.remove(student);
    }

    public long getId() {
        return practical_id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public boolean isValid() {
        return this.name.length() != 0;
    }

}
