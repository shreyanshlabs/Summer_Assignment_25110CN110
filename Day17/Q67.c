#include <stdio.h>

int isPresent(int arr[], int size, int val) {
    for (int i = 0; i < size; i++)
        if (arr[i] == val) return 1;
    return 0;
}

int intersectionArrays(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int count = 0;
    for (int i = 0; i < n1; i++)
        if (isPresent(arr2, n2, arr1[i]))
            result[count++] = arr1[i];
    return count;
}

int main() {
    int a[] = {1, 2, 3, 4};
    int b[] = {3, 4, 5, 6};
    int result[4];

    int size = intersectionArrays(a, 4, b, 4, result);

    printf("Intersection: ");
    for (int i = 0; i < size; i++)
        printf("%d ", result[i]);
    return 0;
}