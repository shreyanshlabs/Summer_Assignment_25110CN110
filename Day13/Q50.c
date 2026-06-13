#include <stdio.h>
void sumAverage(int arr[], int n)
{
    int sum = 0;
    float avg;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    avg = (float)sum / n;
    printf("Sum = %d\n", sum);
    printf("Average = %.2f", avg);
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

    sumAverage(arr, n);

    return 0;
}