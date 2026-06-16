#include <stdio.h>
int main(){
    int n,i;
    printf("Enter value of n: ");
    scanf("%d", &n);

    int arr[n - 1];
     printf("Enter %d elements:\n", n - 1);
    for(i = 0; i < n - 1; i++){
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for(i = 0; i < n - 1; i++){
     sum=sum+arr[i];
    }

    int total = n * (n + 1) / 2;
    int missing = total - sum;
     printf("Missing number = %d\n", missing);
    return 0;
}
