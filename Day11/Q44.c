#include<stdio.h>
int factorial(int);
int main(){
    int n,fact;
    printf("Enter the numbers");
    scanf("%d" ,&n);
    if(n<0){
        printf("Factorial of negattive number is not defined");
    }
    else{
        fact=factorial(n);
        printf("The factorial of number is =%d" ,fact);
    }
    return 0;
}

int factorial(int n)
{
    int i,f=1;
    for(i=1;i<=n;i++)
    {
        f=f*i;
    }
    return(f);
}