
import java.util.Scanner;

interface Employee {
    double earnings(double basic);
    double deductions(double basic);
    double bonus(double basic);
}

class Manager implements Employee {
   
    public double earnings(double basic) {
        double da = 0.8 * basic;
        double hra = 0.15 * basic;
        return basic + da + hra;
    }

    
    public double deductions(double basic) {
        return 0.12 * basic; 
    }
    
    public double bonus(double basic) {
        return 0;
    }
}

class Substaff extends Manager {
    public double bonus(double basic) {
        return 0.5 * basic; 
    }
}

public class q7 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter basic salary: ");
        double basicSalary = scanner.nextDouble();
        Substaff substaff = new Substaff();
        double earnings = substaff.earnings(basicSalary);
        double deductions = substaff.deductions(basicSalary);
        double bonus = substaff.bonus(basicSalary);

        System.out.println("Earnings: " + earnings);
        System.out.println("Deductions: " + deductions);
        System.out.println("Bonus: " + bonus);
        scanner.close();
    }
}

    

