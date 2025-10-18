#include <stdio.h>
#include <string.h>
struct dob {
    int day;
    int month;
    int year;
};

struct student_info {
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

void print_student_info_by_value(struct student_info student) {
    printf("Roll Number: %d\n", student.roll_no);
    printf("Name: %s\n", student.name);
    printf("CGPA: %.2f\n", student.CGPA);
    printf("Date of Birth: %d/%d/%d\n", student.age.day, student.age.month, student.age.year);
}

void print_student_info_by_address(struct student_info *student) {
    printf("Roll Number: %d\n", student->roll_no);
    printf("Name: %s\n", student->name);
    printf("CGPA: %.2f\n", student->CGPA);
    printf("Date of Birth: %d/%d/%d\n", student->age.day, student->age.month, student->age.year);
}

int main() {
    
    struct student_info student = {
        .roll_no = 101,
        .name = "John Doe",
        .CGPA = 3.85,
        .age = {
            .day = 15,
            .month = 7,
            .year = 2000
        }
    };

    printf("Calling print_student_info_by_value:\n");
    print_student_info_by_value(student);

    printf("\nCalling print_student_info_by_address:\n");
    print_student_info_by_address(&student);

    return 0;
}