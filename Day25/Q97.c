#include <stdio.h>

int main() {
    int a[] = {1, 3, 5, 7}, b[] = {2, 4, 6, 8};
    int n1 = 4, n2 = 4;
    int merged[8];
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (a[i] < b[j])
            merged[k++] = a[i++];
        else
            merged[k++] = b[j++];
    }
    while (i < n1) merged[k++] = a[i++];
    while (j < n2) merged[k++] = b[j++];

    printf("Merged Array: ");
    for (int x = 0; x < k; x++)
        printf("%d ", merged[x]);

    return 0;
}