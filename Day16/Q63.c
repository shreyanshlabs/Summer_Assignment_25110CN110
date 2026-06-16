#include <stdio.h>
int main(){
    int n, sum, i, j;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
     printf("Enter required sum: ");
    scanf("%d", &sum);

    printf("Pairs with sum %d are:\n", sum);

    int found = 0;
    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            if(arr[i] + arr[j] == sum){
                printf("(%d, %d)\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }

    if(found == 0){
        printf("No pair found.");
    }
     return 0;
}