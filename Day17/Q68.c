#include <stdio.h>
int isPresent(int arr[], int size, int val) {
    for (int i = 0; i < size; i++)
        if (arr[i] == val) return 1;
    return 0;
}

int commonElements(int a[], int n1, int b[], int n2, int c[], int n3, int result[]) {
    int count = 0;
    for (int i = 0; i < n1; i++)
        if (isPresent(b, n2, a[i]) && isPresent(c, n3, a[i]))
            result[count++] = a[i];
    return count;
}

int main() {
    int a[] = {1, 2, 3, 4};
    int b[] = {2, 3, 4, 5};
    int c[] = {3, 4, 5, 6};
    int result[4];

    int size = commonElements(a, 4, b, 4, c, 4, result);

    printf("Common Elements: ");
    for (int i = 0; i < size; i++)
        printf("%d ", result[i]);
    return 0;
}