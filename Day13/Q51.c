#include <stdio.h>
void largestSmallest(int arr[], int n)
{
    int largest = arr[0];
    int smallest = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > largest)
            largest = arr[i];

        if(arr[i] < smallest)
            smallest = arr[i];
    }

    printf("Largest Element = %d\n", largest);
    printf("Smallest Element = %d", smallest);
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

    largestSmallest(arr, n);

    return 0;
}