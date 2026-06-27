#include <stdio.h>

int main() {
    int age;
    char name[50], hasID;
    
    printf("=== Voting Eligibility System ===\n");
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Do you have a valid ID? (y/n): ");
    scanf(" %c", &hasID);
    
    if (age >= 18 && (hasID == 'y' || hasID == 'Y'))
        printf("%s, You are ELIGIBLE to vote!\n", name);
    else if (age < 18)
        printf("%s, You are NOT eligible. Minimum age is 18.\n", name);
    else
        printf("%s, You need a valid ID to vote.\n", name);
    
    return 0;
}