#include <stdio.h>
int Palindrome(int n) {
    int original = n, reverse = 0, rem;
    while (n > 0) {
        rem = n % 10;
        reverse = reverse * 10 + rem;
        n /= 10;
    }
    return original == reverse;
}

int main() {
    int num;
    scanf("%d", &num);

    if (Palindrome(num))
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}