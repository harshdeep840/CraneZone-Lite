abstract class Student {
    String name;
    int rollNumber;

    public Student(String name, int rollNumber) {
        this.name = name;
        this.rollNumber = rollNumber;
    }

    public abstract void mark();
}
class CIA extends Student {
    public CIA(String name, int rollNumber) {
        super(name, rollNumber);
    }
    public void mark() {
        System.out.println("CIA marks calculated.");
    }
}
class Semester extends Student {
    public Semester(String name, int rollNumber) {
        super(name, rollNumber);
    }
    public void mark() {
        System.out.println("Semester marks calculated.");
    }
}
public class Main {
    public static void main(String[] args) {
        CIA ciaStudent = new CIA("Alice", 101);
        Semester semesterStudent = new Semester("Bob", 201);

        ciaStudent.mark(); 
        semesterStudent.mark(); 
    }
}