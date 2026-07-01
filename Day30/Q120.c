#include <stdio.h>
#include <string.h>

#define MAX 50

struct Item {
    int code;
    char name[50];
    int quantity;
    float price;
};

void addItem(struct Item arr[], int *n) {
    printf("Enter Item Code: ");
    scanf("%d", &arr[*n].code);
    printf("Enter Item Name: ");
    scanf(" %[^\n]", arr[*n].name);
    printf("Enter Quantity: ");
    scanf("%d", &arr[*n].quantity);
    printf("Enter Price: ");
    scanf("%f", &arr[*n].price);
    (*n)++;
    printf("Item added.\n");
}

void displayItems(struct Item arr[], int n) {
    if (n == 0) { printf("No items.\n"); return; }
    printf("\n%-6s %-20s %-10s %-10s\n", "Code", "Name", "Qty", "Price");
    for (int i = 0; i < n; i++)
        printf("%-6d %-20s %-10d %-10.2f\n", arr[i].code, arr[i].name, arr[i].quantity, arr[i].price);
}

int searchItem(struct Item arr[], int n, int code) {
    for (int i = 0; i < n; i++)
        if (arr[i].code == code) return i;
    return -1;
}

void updateStock(struct Item arr[], int n, int code, int qtyChange) {
    int idx = searchItem(arr, n, code);
    if (idx == -1) { printf("Item not found.\n"); return; }
    arr[idx].quantity += qtyChange;
    if (arr[idx].quantity < 0) arr[idx].quantity = 0;
    printf("Stock updated. New quantity: %d\n", arr[idx].quantity);
}

float totalInventoryValue(struct Item arr[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i].quantity * arr[i].price;
    return total;
}

void deleteItem(struct Item arr[], int *n, int code) {
    int idx = searchItem(arr, *n, code);
    if (idx == -1) { printf("Item not found.\n"); return; }
    for (int i = idx; i < *n - 1; i++) arr[i] = arr[i + 1];
    (*n)--;
    printf("Item deleted.\n");
}

int main() {
    struct Item arr[MAX];
    int n = 0, choice, code, qty;

    while (1) {
        printf("\n--- Inventory Management ---\n");
        printf("1.Add Item\n2.Display Items\n3.Search Item\n4.Update Stock\n");
        printf("5.Total Inventory Value\n6.Delete Item\n7.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(arr, &n); break;
            case 2: displayItems(arr, n); break;
            case 3:
                printf("Enter code to search: ");
                scanf("%d", &code);
                int idx = searchItem(arr, n, code);
                if (idx != -1)
                    printf("Found: %s, Qty: %d, Price: %.2f\n", arr[idx].name, arr[idx].quantity, arr[idx].price);
                else
                    printf("Item not found.\n");
                break;
            case 4:
                printf("Enter code: "); scanf("%d", &code);
                printf("Enter quantity change (+/-): "); scanf("%d", &qty);
                updateStock(arr, n, code, qty);
                break;
            case 5:
                printf("Total Inventory Value: %.2f\n", totalInventoryValue(arr, n));
                break;
            case 6:
                printf("Enter code to delete: "); scanf("%d", &code);
                deleteItem(arr, &n, code);
                break;
            case 7: return 0;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}