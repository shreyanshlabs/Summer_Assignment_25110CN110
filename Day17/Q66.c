#include <stdio.h>
int isPresent(int arr[], int size, int val) {
    for (int i = 0; i < size; i++)
        if (arr[i] == val) return 1;
    return 0;
}

int unionArrays(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int count = 0;
    for (int i = 0; i < n1; i++)
        result[count++] = arr1[i];
    for (int i = 0; i < n2; i++)
        if (!isPresent(arr1, n1, arr2[i]))
            result[count++] = arr2[i];
    return count;
}

int main() {
    int a[] = {1, 2, 3, 4};
    int b[] = {3, 4, 5, 6};
    int result[8];

    int size = unionArrays(a, 4, b, 4, result);

    printf("Union: ");
    for (int i = 0; i < size; i++)
        printf("%d ", result[i]);
    return 0;
}