#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);

    printf("Common characters: ");
    for (int i = 0; i < strlen(s1); i++) {
        for (int j = 0; j < strlen(s2); j++) {
            if (s1[i] == s2[j]) {
                printf("%c ", s1[i]);
                break;
            }
        }
    }
    printf("\n");
    return 0;
}