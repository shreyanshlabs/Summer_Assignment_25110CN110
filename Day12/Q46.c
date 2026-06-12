#include <stdio.h>
void Armstrong(int);
int main(){
    int n;
    printf("Enter the number");
    scanf("%d" ,&n);
    Armstrong(n);
    return 0; 
}
void Armstrong(int n)
{
    int x,d,sum=0;
    x=n;
    while(n>0)
    {
        d=n%10;
        sum=sum+d*d*d;
        n=n/10;
    }
    if(sum==x)
    printf("The number is armstrong");
    else
     printf("The number is not armstrong");
}