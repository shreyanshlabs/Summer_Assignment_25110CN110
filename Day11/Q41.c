#include<stdio.h>
int sum(int,int);
int main()
{
    int a,b,result;
    printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);
    result = sum(a,b);
    printf("The sum of two numbers is=%d", result);
    return 0;
}

int sum(int x,int y)
{
    int z;
    z = x + y;
    return z;
}