#include <stdio.h>

int main() {
    char str[200];
    int i, words = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++) {
        if((i == 0 && str[i] != ' ' && str[i] != '\n') ||
           (str[i] != ' ' && str[i - 1] == ' '))
        {
            words++;
        }
    }

    printf("Number of words = %d\n", words);
    return 0;
}