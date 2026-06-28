#include <stdio.h>

void displayArray(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}

int main() {
    int arr[50], n, choice, i, pos, val, temp;

    printf("Enter array size: "); scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    do {
        printf("\n====== Array Operations ======\n");
        printf("1. Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Sort (Ascending)\n");
        printf("5. Sort (Descending)\n");
        printf("6. Search Element\n");
        printf("7. Reverse Array\n");
        printf("8. Find Max & Min\n");
        printf("9. Sum & Average\n");
        printf("10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayArray(arr, n);
                break;

            case 2:
                printf("Enter position (1 to %d): ", n + 1);
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &val);
                for (i = n; i >= pos; i--) arr[i] = arr[i - 1];
                arr[pos - 1] = val;
                n++;
                printf("Inserted! ");
                displayArray(arr, n);
                break;

            case 3:
                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);
                printf("Deleted value: %d\n", arr[pos - 1]);
                for (i = pos - 1; i < n - 1; i++) arr[i] = arr[i + 1];
                n--;
                displayArray(arr, n);
                break;

            case 4:
                bubbleSort(arr, n);
                printf("Sorted Ascending: ");
                displayArray(arr, n);
                break;

            case 5:
                bubbleSort(arr, n);
                for (i = 0; i < n / 2; i++) {
                    temp = arr[i]; arr[i] = arr[n-1-i]; arr[n-1-i] = temp;
                }
                printf("Sorted Descending: ");
                displayArray(arr, n);
                break;

            case 6:
                printf("Enter value to search: "); scanf("%d", &val);
                pos = linearSearch(arr, n, val);
                if (pos != -1) printf("Found at index %d (position %d)\n", pos, pos + 1);
                else printf("Element not found!\n");
                break;

            case 7:
                for (i = 0; i < n / 2; i++) {
                    temp = arr[i]; arr[i] = arr[n-1-i]; arr[n-1-i] = temp;
                }
                printf("Reversed: ");
                displayArray(arr, n);
                break;

            case 8: {
                int max = arr[0], min = arr[0];
                for (i = 1; i < n; i++) {
                    if (arr[i] > max) max = arr[i];
                    if (arr[i] < min) min = arr[i];
                }
                printf("Maximum: %d | Minimum: %d\n", max, min);
                break;
            }

            case 9: {
                int sum = 0;
                for (i = 0; i < n; i++) sum += arr[i];
                printf("Sum: %d | Average: %.2f\n", sum, (float)sum / n);
                break;
            }

            case 10:
                printf("Exiting Array Operations. Goodbye!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 10);

    return 0;
}