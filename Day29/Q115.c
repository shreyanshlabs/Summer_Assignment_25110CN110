#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
        if (tolower(str[i]) != tolower(str[len - 1 - i])) return 0;
    return 1;
}

int countVowels(char str[]) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') count++;
    }
    return count;
}

int countWords(char str[]) {
    int count = 0, inWord = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ' && !inWord) { count++; inWord = 1; }
        else if (str[i] == ' ') inWord = 0;
    }
    return count;
}

int main() {
    char str[100], str2[100], temp[100];
    int choice, i;

    do {
        printf("\n====== String Operations Menu ======\n");
        printf("1.  String Length\n");
        printf("2.  Uppercase\n");
        printf("3.  Lowercase\n");
        printf("4.  Reverse String\n");
        printf("5.  Palindrome Check\n");
        printf("6.  Concatenate Strings\n");
        printf("7.  Compare Strings\n");
        printf("8.  Copy String\n");
        printf("9.  Count Vowels\n");
        printf("10. Count Words\n");
        printf("11. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 10) {
            printf("Enter string: ");
            scanf(" %[^\n]", str);
        }

        switch (choice) {
            case 1:
                printf("Length of \"%s\" = %lu\n", str, strlen(str));
                break;

            case 2:
                for (i = 0; str[i]; i++) str[i] = toupper(str[i]);
                printf("Uppercase: %s\n", str);
                break;

            case 3:
                for (i = 0; str[i]; i++) str[i] = tolower(str[i]);
                printf("Lowercase: %s\n", str);
                break;

            case 4:
                strcpy(temp, str);
                int len = strlen(temp), t;
                for (i = 0; i < len / 2; i++) {
                    t = temp[i]; temp[i] = temp[len-1-i]; temp[len-1-i] = t;
                }
                printf("Reversed: %s\n", temp);
                break;

            case 5:
                printf("\"%s\" is %s palindrome.\n", str, isPalindrome(str) ? "a" : "NOT a");
                break;

            case 6:
                printf("Enter second string: ");
                scanf(" %[^\n]", str2);
                strcat(str, str2);
                printf("Concatenated: %s\n", str);
                break;

            case 7:
                printf("Enter second string: ");
                scanf(" %[^\n]", str2);
                int cmp = strcmp(str, str2);
                if (cmp == 0) printf("Strings are EQUAL.\n");
                else if (cmp < 0) printf("\"%s\" comes BEFORE \"%s\"\n", str, str2);
                else printf("\"%s\" comes AFTER \"%s\"\n", str, str2);
                break;

            case 8:
                strcpy(temp, str);
                printf("Copied string: %s\n", temp);
                break;

            case 9:
                printf("Vowel count in \"%s\" = %d\n", str, countVowels(str));
                break;

            case 10:
                printf("Word count in \"%s\" = %d\n", str, countWords(str));
                break;

            case 11:
                printf("Exiting String Operations. Goodbye!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 11);

    return 0;
}