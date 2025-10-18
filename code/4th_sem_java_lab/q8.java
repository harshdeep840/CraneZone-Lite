interface Employee {
    void getDetails();
}

interface Manager extends Employee {
    void getDeptDetails();
}

class Head implements Manager {
    private String empId;
    private String empName;
    private String deptId;
    private String deptName;

    public Head(String empId, String empName, String deptId, String deptName) {
        this.empId = empId;
        this.empName = empName;
        this.deptId = deptId;
        this.deptName = deptName;
    }
    @Override
    public void getDetails() {
        System.out.println("Employee ID: " + empId);
        System.out.println("Employee Name: " + empName);
    }

    @Override
    public void getDeptDetails() {
        System.out.println("Department ID: " + deptId);
        System.out.println("Department Name: " + deptName);
    }
}

public class q8 {
    public static void main(String[] args) {

        Head headOfDept = new Head("E001", "John Doe", "D001", "Engineering");

        System.out.println("Head of Department Details:");
        headOfDept.getDetails();
        headOfDept.getDeptDetails();
    }
}
