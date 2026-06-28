#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[30];
    int available;  // 1 = available, 0 = issued
};

void displayBooks(struct Book lib[], int n) {
    printf("\n%-5s %-25s %-20s %-10s\n", "ID", "Title", "Author", "Status");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("%-5d %-25s %-20s %-10s\n",
               lib[i].id, lib[i].title, lib[i].author,
               lib[i].available ? "Available" : "Issued");
}

int main() {
    struct Book lib[10];
    int count = 0, choice, id, i, found;

    do {
        printf("\n====== Library Management System ======\n");
        printf("1. Add Book\n");
        printf("2. View All Books\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Search Book\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Book ID: ");
                scanf("%d", &lib[count].id);
                printf("Title: ");
                scanf(" %[^\n]", lib[count].title);
                printf("Author: ");
                scanf(" %[^\n]", lib[count].author);
                lib[count].available = 1;
                count++;
                printf("Book added successfully!\n");
                break;

            case 2:
                if (count == 0)
                    printf("No books in library!\n");
                else
                    displayBooks(lib, count);
                break;

            case 3:
                printf("Enter Book ID to issue: ");
                scanf("%d", &id);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (lib[i].id == id) {
                        found = 1;
                        if (lib[i].available) {
                            lib[i].available = 0;
                            printf("Book '%s' issued successfully!\n", lib[i].title);
                        } else {
                            printf("Book is already issued!\n");
                        }
                        break;
                    }
                }
                if (!found) printf("Book not found!\n");
                break;

            case 4:
                printf("Enter Book ID to return: ");
                scanf("%d", &id);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (lib[i].id == id) {
                        found = 1;
                        lib[i].available = 1;
                        printf("Book '%s' returned successfully!\n", lib[i].title);
                        break;
                    }
                }
                if (!found) printf("Book not found!\n");
                break;

            case 5:
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (lib[i].id == id) {
                        printf("\nID    : %d\n", lib[i].id);
                        printf("Title : %s\n", lib[i].title);
                        printf("Author: %s\n", lib[i].author);
                        printf("Status: %s\n", lib[i].available ? "Available" : "Issued");
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Book not found!\n");
                break;

            case 6:
                printf("Thank you! Exiting Library System.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}