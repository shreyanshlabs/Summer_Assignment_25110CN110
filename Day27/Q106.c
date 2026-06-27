#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    char dept[30];
    float salary;
};

int main() {
    int n, i, choice;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    struct Employee emp[n];
    
    for (i = 0; i < n; i++) {
        printf("\nEmployee %d Details:\n", i + 1);
        printf("ID: "); scanf("%d", &emp[i].id);
        printf("Name: "); scanf("%s", emp[i].name);
        printf("Department: "); scanf("%s", emp[i].dept);
        printf("Salary: "); scanf("%f", &emp[i].salary);
    }
    
    printf("\n=== Employee Records ===\n");
    printf("%-5s %-15s %-15s %-10s\n", "ID", "Name", "Department", "Salary");
    for (i = 0; i < n; i++)
        printf("%-5d %-15s %-15s %-10.2f\n",
               emp[i].id, emp[i].name, emp[i].dept, emp[i].salary);
    
    // Find highest salary
    int maxIdx = 0;
    for (i = 1; i < n; i++)
        if (emp[i].salary > emp[maxIdx].salary) maxIdx = i;
    printf("\nHighest Paid: %s (Rs. %.2f)\n", emp[maxIdx].name, emp[maxIdx].salary);
    
    return 0;
}