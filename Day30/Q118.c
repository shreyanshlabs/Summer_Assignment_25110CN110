#include <stdio.h>
#include <string.h>

#define MAX 50

struct Book {
    int id;
    char title[50];
    char author[30];
    int isIssued; // 0 = available, 1 = issued
};

void addBook(struct Book b[], int *n) {
    printf("Enter Book ID: ");
    scanf("%d", &b[*n].id);
    printf("Enter Title: ");
    scanf(" %[^\n]", b[*n].title);
    printf("Enter Author: ");
    scanf(" %[^\n]", b[*n].author);
    b[*n].isIssued = 0;
    (*n)++;
    printf("Book added.\n");
}

void displayBooks(struct Book b[], int n) {
    printf("\n%-5s %-20s %-15s %-10s\n", "ID", "Title", "Author", "Status");
    for (int i = 0; i < n; i++)
        printf("%-5d %-20s %-15s %-10s\n", b[i].id, b[i].title, b[i].author,
               b[i].isIssued ? "Issued" : "Available");
}

void issueBook(struct Book b[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (b[i].id == id) {
            if (b[i].isIssued) printf("Already issued.\n");
            else { b[i].isIssued = 1; printf("Book issued.\n"); }
            return;
        }
    }
    printf("Book not found.\n");
}

void returnBook(struct Book b[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (b[i].id == id) {
            b[i].isIssued = 0;
            printf("Book returned.\n");
            return;
        }
    }
    printf("Book not found.\n");
}

int main() {
    struct Book b[MAX];
    int n = 0, choice, id;

    while (1) {
        printf("\n1.Add 2.Display 3.Issue 4.Return 5.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(b, &n); break;
            case 2: displayBooks(b, n); break;
            case 3:
                printf("Enter Book ID to issue: ");
                scanf("%d", &id);
                issueBook(b, n, id);
                break;
            case 4:
                printf("Enter Book ID to return: ");
                scanf("%d", &id);
                returnBook(b, n, id);
                break;
            case 5: return 0;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}




































































































































