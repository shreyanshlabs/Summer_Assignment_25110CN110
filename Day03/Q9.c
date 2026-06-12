#include<stdio.h>
int main(){
    int n,prime=1,i;
    printf("Enter the number greaatervthan 1");
    scanf("%d" ,&n);
    for(i=2;i<=n/2;i++){
        if(n%i==0)
        {
            prime=0;
            break;
        }
    }
    if(prime==1){
        printf("%dis prime" ,n);
    }
    else
    {
        printf("%d is not prime" ,n);

    }
    return 0;
}