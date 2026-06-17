#include <stdio.h>
void mergeArrays(int arr1[], int n1, int arr2[], int n2, int result[]) {
    for (int i = 0; i < n1; i++)
        result[i] = arr1[i];
    for (int i = 0; i < n2; i++)
        result[n1 + i] = arr2[i];
}

int main() {
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int n1 = 3, n2 = 3;
    int result[6];

    mergeArrays(a, n1, b, n2, result);

    printf("Merged Array: ");
    for (int i = 0; i < n1 + n2; i++)
        printf("%d ", result[i]);
    return 0;
}