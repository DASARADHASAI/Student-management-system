#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variable to keep track of number of students
int i = 0;

// Structure to store the student
struct sinfo {
    char fname[50];
    char lname[50];
    int roll;
    float cgpa;
    int cid[5];
} st[55];

// Function to add the student
void add_student() {
    printf("\nAdd the Student Details\n");
    printf("-------------------------\n");
    printf("Enter the first name of the student: ");
    scanf("%s", st[i].fname);
    printf("Enter the last name of the student: ");
    scanf("%s", st[i].lname);
    printf("Enter the Roll Number: ");
    scanf("%d", &st[i].roll);
    printf("Enter the CGPA obtained: ");
    scanf("%f", &st[i].cgpa);
    printf("Enter the course IDs of 5 courses: ");
    for (int j = 0; j < 5; j++) {
        scanf("%d", &st[i].cid[j]);
    }
    i++;
    printf("Student added successfully!\n");
}

// Function to find the student by roll number
void find_rl() {
    int x;
    printf("\nEnter the Roll Number of the student: ");
    scanf("%d", &x);
    for (int j = 0; j < i; j++) {
        if (x == st[j].roll) {
            printf("\nThe Student's Details are\n");
            printf("First name: %s\n", st[j].fname);
            printf("Last name: %s\n", st[j].lname);
            printf("CGPA: %.2f\n", st[j].cgpa);
            printf("Course IDs: ");
            for (int k = 0; k < 5; k++) {
                printf("%d ", st[j].cid[k]);
            }
            printf("\n");
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", x);
}

// Function to find the student by first name
void find_fn() {
    char a[50];
    printf("\nEnter the First Name of the student: ");
    scanf("%s", a);
    for (int j = 0; j < i; j++) {
        if (strcmp(st[j].fname, a) == 0) {
            printf("\nThe Student's Details are\n");
            printf("First name: %s\n", st[j].fname);
            printf("Last name: %s\n", st[j].lname);
            printf("Roll Number: %d\n", st[j].roll);
            printf("CGPA: %.2f\n", st[j].cgpa);
            printf("Course IDs: ");
            for (int k = 0; k < 5; k++) {
                printf("%d ", st[j].cid[k]);
            }
            printf("\n");
            return;
        }
    }
    printf("Student with First Name %s not found.\n", a);
}

// Function to find the students enrolled in a particular course
void find_c() {
    int id;
    printf("\nEnter the Course ID: ");
    scanf("%d", &id);
    int found = 0;
    for (int j = 0; j < i; j++) {
        for (int k = 0; k < 5; k++) {
            if (id == st[j].cid[k]) {
                if (!found) {
                    printf("\nStudents enrolled in Course ID %d:\n", id);
                }
                printf("\nThe Student's Details are\n");
                printf("First name: %s\n", st[j].fname);
                printf("Last name: %s\n", st[j].lname);
                printf("Roll Number: %d\n", st[j].roll);
                printf("CGPA: %.2f\n", st[j].cgpa);
                found = 1;
                break;
            }
        }
    }
    if (!found) {
        printf("No students found enrolled in Course ID %d.\n", id);
    }
}

// Function to print the total number of students
void tot_s() {
    printf("\nThe total number of students is %d\n", i);
    printf("You can have a maximum of 50 students\n");
    printf("You can add %d more students\n", 50 - i);
}

// Function to delete a student by roll number
void del_s() {
    int a;
    printf("\nEnter the Roll Number of the student to delete: ");
    scanf("%d", &a);
    for (int j = 0; j < i; j++) {
        if (a == st[j].roll) {
            for (int k = j; k < i - 1; k++) {
                st[k] = st[k + 1];
            }
            i--;
            printf("Student with Roll Number %d has been removed successfully.\n", a);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", a);
}

// Function to update a student's data
void up_s() {
    int x;
    printf("\nEnter the Roll Number to update the entry: ");
    scanf("%d", &x);
    for (int j = 0; j < i; j++) {
        if (st[j].roll == x) {
            printf("1. First name\n");
            printf("2. Last name\n");
            printf("3. Roll number\n");
            printf("4. CGPA\n");
            printf("5. Courses\n");
            printf("Enter the number to update the corresponding field: ");
            int z;
            scanf("%d", &z);
            switch (z) {
                case 1:
                    printf("Enter the new first name: ");
                    scanf("%s", st[j].fname);
                    break;
                case 2:
                    printf("Enter the new last name: ");
                    scanf("%s", st[j].lname);
                    break;
                case 3:
                    printf("Enter the new roll number: ");
                    scanf("%d", &st[j].roll);
                    break;
                case 4:
                    printf("Enter the new CGPA: ");
                    scanf("%f", &st[j].cgpa);
                    break;
                case 5:
                    printf("Enter the new course IDs: ");
                    for (int k = 0; k < 5; k++) {
                        scanf("%d", &st[j].cid[k]);
                    }
                    break;
                default:
                    printf("Invalid choice.\n");
                    return;
            }
            printf("Student details updated successfully.\n");
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", x);
}

// Driver code
int main() {
    int choice;
    while (1) {
        printf("\nThe Task that you want to perform\n");
        printf("1. Add the Student Details\n");
        printf("2. Find the Student Details by Roll Number\n");
        printf("3. Find the Student Details by First Name\n");
        printf("4. Find the Student Details by Course ID\n");
        printf("5. Find the Total number of Students\n");
        printf("6. Delete the Student Details by Roll Number\n");
        printf("7. Update the Student Details by Roll Number\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                find_rl();
                break;
            case 3:
                find_fn();
                break;
            case 4:
                find_c();
                break;
            case 5:
                tot_s();
                break;
            case 6:
                del_s();
                break;
            case 7:
                up_s();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 8.\n");
        }
    }
    return 0;
}
