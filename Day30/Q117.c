#include <stdio.h>
#include <string.h>

#define MAX 50

struct Student {
    int roll;
    char name[50];
    float marks;
};

void addStudent(struct Student s[], int *n) {
    printf("Enter Roll No: ");
    scanf("%d", &s[*n].roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", s[*n].name);
    printf("Enter Marks: ");
    scanf("%f", &s[*n].marks);
    (*n)++;
    printf("Student added successfully!\n");
}

void displayAll(struct Student s[], int n) {
    if (n == 0) { printf("No records found.\n"); return; }
    printf("\n%-6s %-20s %-6s\n", "Roll", "Name", "Marks");
    for (int i = 0; i < n; i++)
        printf("%-6d %-20s %-6.2f\n", s[i].roll, s[i].name, s[i].marks);
}

void searchStudent(struct Student s[], int n, int roll) {
    for (int i = 0; i < n; i++) {
        if (s[i].roll == roll) {
            printf("Found: %s, Marks: %.2f\n", s[i].name, s[i].marks);
            return;
        }
    }
    printf("Student not found.\n");
}

void deleteStudent(struct Student s[], int *n, int roll) {
    int idx = -1;
    for (int i = 0; i < *n; i++)
        if (s[i].roll == roll) { idx = i; break; }
    if (idx == -1) { printf("Not found.\n"); return; }
    for (int i = idx; i < *n - 1; i++) s[i] = s[i + 1];
    (*n)--;
    printf("Deleted successfully.\n");
}

int main() {
    struct Student s[MAX];
    int n = 0, choice, roll;

    while (1) {
        printf("\n1.Add 2.Display 3.Search 4.Delete 5.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(s, &n); break;
            case 2: displayAll(s, n); break;
            case 3:
                printf("Enter roll to search: ");
                scanf("%d", &roll);
                searchStudent(s, n, roll);
                break;
            case 4:
                printf("Enter roll to delete: ");
                scanf("%d", &roll);
                deleteStudent(s, &n, roll);
                break;
            case 5: return 0;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}