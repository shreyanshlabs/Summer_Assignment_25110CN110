#include <stdio.h>
int Perfect(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0)
            sum += i;
    }

    return sum == n;
}

int main() {
    int num;
    scanf("%d", &num);
    if (Perfect(num))
        printf("Perfect Number");
    else
        printf("Not Perfect Number");

    return 0;
}