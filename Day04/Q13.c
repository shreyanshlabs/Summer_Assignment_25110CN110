#include<stdio.h>
int main(){
    int n =0,i=0;
    int f1=0,f2=1,f3;
    printf("Enter number of terms");
    scanf("%d" ,&n);
    printf("%d\t%d" ,f1,f2);
    for(i=1;i<=n-2;i++){
        f3=f1+f2;
        printf("\t%d" ,f3);
        f1=f2;
        f2=f3;
    }
    return 0;
}