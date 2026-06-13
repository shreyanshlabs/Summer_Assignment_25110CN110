#include <stdio.h>
void countEvenOdd(int arr[], int n)
{
    int even = 0, odd = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    printf("Even Elements = %d\n", even);
    printf("Odd Elements = %d", odd);
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

    countEvenOdd(arr, n);
    return 0;
}