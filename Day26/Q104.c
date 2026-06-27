#include <stdio.h>

int main() {
    int answer, score = 0;
    
    printf("=== Quiz Application ===\n\n");
    
    printf("Q1. What is the capital of India?\n");
    printf("1. Mumbai  2. Delhi  3. Kolkata  4. Chennai\n");
    printf("Your answer: ");
    scanf("%d", &answer);
    if (answer == 2) { printf("Correct!\n"); score++; }
    else printf("Wrong! Answer is Delhi.\n");
    
    printf("\nQ2. Which language is used for system programming?\n");
    printf("1. Python  2. Java  3. C  4. HTML\n");
    printf("Your answer: ");
    scanf("%d", &answer);
    if (answer == 3) { printf("Correct!\n"); score++; }
    else printf("Wrong! Answer is C.\n");
    
    printf("\nQ3. How many bytes in a kilobyte?\n");
    printf("1. 100  2. 512  3. 1024  4. 2048\n");
    printf("Your answer: ");
    scanf("%d", &answer);
    if (answer == 3) { printf("Correct!\n"); score++; }
    else printf("Wrong! Answer is 1024.\n");
    
    printf("\n=== Quiz Over! Your Score: %d/3 ===\n", score);
    if (score == 3) printf("Excellent!\n");
    else if (score == 2) printf("Good!\n");
    else printf("Keep practicing!\n");
    
    return 0;
}