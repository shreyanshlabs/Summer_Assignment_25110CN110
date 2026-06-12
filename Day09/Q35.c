#include <stdio.h>

int main() {
    int n = 5;

    for(int i = 1; i <= n; i++) {
        char ch = 'A' + i - 1;

        for(int j = 1; j <= i; j++) {
            printf("%c", ch);
        }
        printf("\n");
    }

    return 0;
}