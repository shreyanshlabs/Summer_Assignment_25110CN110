#include <stdio.h>
#include <string.h>

struct Contact {
    int id;
    char name[50];
    char phone[15];
    char email[50];
    char city[30];
};

void displayContact(struct Contact c) {
    printf("\nID    : %d\n", c.id);
    printf("Name  : %s\n", c.name);
    printf("Phone : %s\n", c.phone);
    printf("Email : %s\n", c.email);
    printf("City  : %s\n", c.city);
}

int main() {
    struct Contact contacts[20];
    int count = 0, choice, id, i, found;
    char searchName[50];

    do {
        printf("\n====== Contact Management System ======\n");
        printf("1. Add Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search by Name\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                contacts[count].id = count + 1;
                printf("Name  : "); scanf(" %[^\n]", contacts[count].name);
                printf("Phone : "); scanf("%s", contacts[count].phone);
                printf("Email : "); scanf("%s", contacts[count].email);
                printf("City  : "); scanf("%s", contacts[count].city);
                count++;
                printf("Contact added successfully!\n");
                break;

            case 2:
                if (count == 0) { printf("No contacts found!\n"); break; }
                printf("\n%-5s %-18s %-14s %-22s %-15s\n",
                       "ID", "Name", "Phone", "Email", "City");
                printf("------------------------------------------------------------------------\n");
                for (i = 0; i < count; i++)
                    if (contacts[i].id != -1)
                        printf("%-5d %-18s %-14s %-22s %-15s\n",
                               contacts[i].id, contacts[i].name, contacts[i].phone,
                               contacts[i].email, contacts[i].city);
                break;

            case 3:
                printf("Enter name to search: ");
                scanf(" %[^\n]", searchName);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (strcasecmp(contacts[i].name, searchName) == 0 && contacts[i].id != -1) {
                        displayContact(contacts[i]);
                        found = 1;
                    }
                }
                if (!found) printf("Contact not found!\n");
                break;

            case 4:
                printf("Enter Contact ID to update: ");
                scanf("%d", &id);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (contacts[i].id == id) {
                        printf("New Phone : "); scanf("%s", contacts[i].phone);
                        printf("New Email : "); scanf("%s", contacts[i].email);
                        printf("New City  : "); scanf("%s", contacts[i].city);
                        printf("Contact updated!\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Contact not found!\n");
                break;

            case 5:
                printf("Enter Contact ID to delete: ");
                scanf("%d", &id);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (contacts[i].id == id) {
                        contacts[i].id = -1;   // mark deleted
                        printf("Contact deleted!\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Contact not found!\n");
                break;

            case 6:
                printf("Exiting Contact Manager. Goodbye!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}