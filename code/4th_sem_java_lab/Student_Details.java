import java.util.Scanner;

class Student{
    int roll;
    String name;
    double cgpa;

    public Student(int roll, String name, double cgpa) {
        this.roll = roll;
        this.name = name;
        this.cgpa = cgpa;
    }
}

public class Student_Details {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of students: ");
        int n = scanner.nextInt();

        Student[] students = new Student[n];
        for (int i = 0; i < n; i++) {
            System.out.println("\nEnter details for student " + (i + 1) + ":");
            System.out.print("Roll Number: ");
            int roll = scanner.nextInt();
            scanner.nextLine(); 
            System.out.print("Name: ");
            String name = scanner.nextLine();
            System.out.print("CGPA: ");
            double cgpa = scanner.nextDouble();

            students[i] = new Student(roll, name, cgpa);
        }
        System.out.println("\nDetails of all students:");
        for (int i = 0; i < n; i++) {
            System.out.println("Student " + (i + 1) + ":");
            System.out.println("Roll Number: " + students[i].roll);
            System.out.println("Name: " + students[i].name);
            System.out.println("CGPA: " + students[i].cgpa);
            System.out.println();
        }
        double lowestCGPA = students[0].cgpa;
        int lowestCGPAIndex = 0;
        for (int i = 1; i < n; i++) {
            if (students[i].cgpa < lowestCGPA) {
                lowestCGPA = students[i].cgpa;
                lowestCGPAIndex = i;
            }
        }
        System.out.println("Student with the lowest CGPA:");
        System.out.println("Name: " + students[lowestCGPAIndex].name);
        System.out.println("Roll Number: " + students[lowestCGPAIndex].roll);
        System.out.println("CGPA: " + students[lowestCGPAIndex].cgpa);

        scanner.close();
    }
}
