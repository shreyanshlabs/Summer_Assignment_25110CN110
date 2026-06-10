#include <stdio.h>
int main() {
    int n = 5;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i; j++)
            printf(" ");

        for(char ch = 'A'; ch < 'A' + i; ch++)
            printf("%c", ch);

        for(char ch = 'A' + i - 2; ch >= 'A'; ch--)
            printf("%c", ch);

        printf("\n");
    }

    return 0;
}