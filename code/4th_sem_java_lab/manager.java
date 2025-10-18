import java.util.Scanner;

// Define the interface
interface Employee {
    double earnings(double basic);
    double deductions(double basic);
    double bonus(double basic);
}

// Manager class implementing the Employee interface
class Manager implements Employee {
   
    public double earnings(double basic) {
        double da = 0.8 * basic;
        double hra = 0.15 * basic;
        return basic + da + hra;
    }

    
    public double deductions(double basic) {
        return 0.12 * basic; // PF deduction
    }

    // Bonus method not implemented here
    
    public double bonus(double basic) {
        // Not implemented in Manager class
        return 0;
    }
}

// Substaff class extending Manager class and implementing bonus method
class Substaff extends Manager {
    public double bonus(double basic) {
        return 0.5 * basic; // 50% of basic as bonus
    }
}

public class manager {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input basic salary from user
        System.out.print("Enter basic salary: ");
        double basicSalary = scanner.nextDouble();

        // Create Substaff object
        Substaff substaff = new Substaff();

        // Calculate earnings, deductions, and bonus
        double earnings = substaff.earnings(basicSalary);
        double deductions = substaff.deductions(basicSalary);
        double bonus = substaff.bonus(basicSalary);

        // Output the results
        System.out.println("Earnings: " + earnings);
        System.out.println("Deductions: " + deductions);
        System.out.println("Bonus: " + bonus);

        // Close the scanner
        scanner.close();
    }
}
