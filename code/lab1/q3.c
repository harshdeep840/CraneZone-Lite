#include <stdio.h>

struct Employee {
    int empId;
    char name[50];
    char designation[50];
    float basicSalary;
    float hraPercentage;
    float daPercentage;
};

// Function to calculate gross salary
float calculateGrossSalary(float basicSalary, float hraPercentage, float daPercentage) {
    float hra = (hraPercentage / 100) * basicSalary;
    float da = (daPercentage / 100) * basicSalary;
    return basicSalary + hra + da;
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];

    // Input employee information
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &employees[i].empId);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Designation: ");
        scanf("%s", employees[i].designation);
        printf("Basic Salary: ");
        scanf("%f", &employees[i].basicSalary);
        printf("HRA Percentage: ");
        scanf("%f", &employees[i].hraPercentage);
        printf("DA Percentage: ");
        scanf("%f", &employees[i].daPercentage);
    }

    // Display employee information with gross salary
    printf("\nEmployee Information with Gross Salary:\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < n; i++) {
        float grossSalary = calculateGrossSalary(employees[i].basicSalary,
                                                 employees[i].hraPercentage,
                                                 employees[i].daPercentage);
        printf("Employee ID: %d\n", employees[i].empId);
        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Gross Salary: $%.2f\n", grossSalary);
        printf("--------------------------------------\n");
    }

    return 0;
}
