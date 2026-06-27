#include <stdio.h>

int main() {
    char name[50];
    int rollNo;
    float sub[5], total = 0, avg;
    char grade;
    int i;
    char subjects[5][20] = {"Maths", "Science", "English", "History", "CS"};
    
    printf("=== Marksheet Generation System ===\n");
    printf("Student Name: "); scanf("%s", name);
    printf("Roll Number: "); scanf("%d", &rollNo);
    
    for (i = 0; i < 5; i++) {
        printf("Enter marks for %s (out of 100): ", subjects[i]);
        scanf("%f", &sub[i]);
        total += sub[i];
    }
    
    avg = total / 5;
    if (avg >= 90) grade = 'A';
    else if (avg >= 75) grade = 'B';
    else if (avg >= 60) grade = 'C';
    else if (avg >= 40) grade = 'D';
    else grade = 'F';
    
    printf("\n========== MARKSHEET ==========\n");
    printf("Name: %-20s Roll: %d\n", name, rollNo);
    printf("--------------------------------\n");
    for (i = 0; i < 5; i++)
        printf("%-15s: %.2f\n", subjects[i], sub[i]);
    printf("--------------------------------\n");
    printf("Total  : %.2f / 500\n", total);
    printf("Average: %.2f%%\n", avg);
    printf("Grade  : %c\n", grade);
    printf(avg >= 40 ? "Result : PASS\n" : "Result : FAIL\n");
    
    return 0;
}