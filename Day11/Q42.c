#include<stdio.h>
int max(int,int);
int main(){
    int a,b,big;
    printf("Enter two numbers");
    scanf("%d %d" ,&a,&b);
    big=max(a,b);
    printf("The bigger numbers is= %d" ,big);
    return 0;
}

int max(int x,int y )
{
    if(x>y)
    return(x);
    else
    return(y);
}