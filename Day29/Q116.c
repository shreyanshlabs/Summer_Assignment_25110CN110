#include <stdio.h>
#include <string.h>

struct Item {
    int id;
    char name[30];
    char category[20];
    int quantity;
    float price;
};

void displayItem(struct Item it) {
    printf("%-5d %-18s %-12s %-10d Rs.%-10.2f\n",
           it.id, it.name, it.category, it.quantity, it.price);
}

int main() {
    struct Item inv[30];
    int count = 0, choice, id, i, found;
    int qty;

    do {
        printf("\n====== Inventory Management System ======\n");
        printf("1. Add Item\n");
        printf("2. View All Items\n");
        printf("3. Search Item\n");
        printf("4. Update Stock\n");
        printf("5. Delete Item\n");
        printf("6. Total Inventory Value\n");
        printf("7. Low Stock Alert (qty < 5)\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inv[count].id = count + 1;
                printf("Item Name    : "); scanf(" %[^\n]", inv[count].name);
                printf("Category     : "); scanf("%s", inv[count].category);
                printf("Quantity     : "); scanf("%d", &inv[count].quantity);
                printf("Price per unit: Rs. "); scanf("%f", &inv[count].price);
                count++;
                printf("Item added!\n");
                break;

            case 2:
                if (count == 0) { printf("Inventory is empty!\n"); break; }
                printf("\n%-5s %-18s %-12s %-10s %-10s\n",
                       "ID", "Name", "Category", "Qty", "Price");
                printf("----------------------------------------------------------\n");
                for (i = 0; i < count; i++)
                    if (inv[i].id != -1) displayItem(inv[i]);
                break;

            case 3:
                printf("Enter Item ID: "); scanf("%d", &id);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (inv[i].id == id && inv[i].id != -1) {
                        printf("\nID       : %d\n", inv[i].id);
                        printf("Name     : %s\n", inv[i].name);
                        printf("Category : %s\n", inv[i].category);
                        printf("Quantity : %d\n", inv[i].quantity);
                        printf("Price    : Rs. %.2f\n", inv[i].price);
                        found = 1; break;
                    }
                }
                if (!found) printf("Item not found!\n");
                break;

            case 4:
                printf("Enter Item ID to update stock: "); scanf("%d", &id);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (inv[i].id == id && inv[i].id != -1) {
                        printf("Current Stock: %d\n", inv[i].quantity);
                        printf("Enter new quantity: "); scanf("%d", &inv[i].quantity);
                        printf("Stock updated!\n");
                        found = 1; break;
                    }
                }
                if (!found) printf("Item not found!\n");
                break;

            case 5:
                printf("Enter Item ID to delete: "); scanf("%d", &id);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (inv[i].id == id && inv[i].id != -1) {
                        inv[i].id = -1;
                        printf("Item deleted!\n");
                        found = 1; break;
                    }
                }
                if (!found) printf("Item not found!\n");
                break;

            case 6: {
                float total = 0;
                for (i = 0; i < count; i++)
                    if (inv[i].id != -1) total += inv[i].quantity * inv[i].price;
                printf("Total Inventory Value: Rs. %.2f\n", total);
                break;
            }

            case 7:
                printf("\n=== Low Stock Alert (Qty < 5) ===\n");
                found = 0;
                for (i = 0; i < count; i++) {
                    if (inv[i].id != -1 && inv[i].quantity < 5) {
                        printf("!! %s | Qty: %d\n", inv[i].name, inv[i].quantity);
                        found = 1;
                    }
                }
                if (!found) printf("All items have sufficient stock!\n");
                break;

            case 8:
                printf("Exiting Inventory System. Goodbye!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 8);

    return 0;
}