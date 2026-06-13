#include <stdio.h>
void displayArray(int arr[], int n)
{
    printf("Array elements are:\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    displayArray(arr, n);

    return 0;
}