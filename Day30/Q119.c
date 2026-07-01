#include <stdio.h>
#include <string.h>

#define MAX 50

struct Employee {
    int id;
    char name[50];
    char dept[30];
    float salary;
};

void addEmployee(struct Employee e[], int *n) {
    printf("Enter Employee ID: ");
    scanf("%d", &e[*n].id);
    printf("Enter Name: ");
    scanf(" %[^\n]", e[*n].name);
    printf("Enter Department: ");
    scanf(" %[^\n]", e[*n].dept);
    printf("Enter Salary: ");
    scanf("%f", &e[*n].salary);
    (*n)++;
    printf("Employee added.\n");
}

void displayEmployees(struct Employee e[], int n) {
    printf("\n%-5s %-20s %-15s %-10s\n", "ID", "Name", "Dept", "Salary");
    for (int i = 0; i < n; i++)
        printf("%-5d %-20s %-15s %-10.2f\n", e[i].id, e[i].name, e[i].dept, e[i].salary);
}

void updateSalary(struct Employee e[], int n, int id, float newSalary) {
    for (int i = 0; i < n; i++) {
        if (e[i].id == id) {
            e[i].salary = newSalary;
            printf("Salary updated.\n");
            return;
        }
    }
    printf("Employee not found.\n");
}

void deleteEmployee(struct Employee e[], int *n, int id) {
    int idx = -1;
    for (int i = 0; i < *n; i++)
        if (e[i].id == id) { idx = i; break; }
    if (idx == -1) { printf("Not found.\n"); return; }
    for (int i = idx; i < *n - 1; i++) e[i] = e[i + 1];
    (*n)--;
    printf("Employee deleted.\n");
}

int main() {
    struct Employee e[MAX];
    int n = 0, choice, id;
    float sal;

    while (1) {
        printf("\n1.Add 2.Display 3.Update Salary 4.Delete 5.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addEmployee(e, &n); break;
            case 2: displayEmployees(e, n); break;
            case 3:
                printf("Enter ID: "); scanf("%d", &id);
                printf("Enter new salary: "); scanf("%f", &sal);
                updateSalary(e, n, id, sal);
                break;
            case 4:
                printf("Enter ID to delete: "); scanf("%d", &id);
                deleteEmployee(e, &n, id);
                break;
            case 5: return 0;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}