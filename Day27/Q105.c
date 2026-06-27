#include <stdio.h>

struct Student {
    int id;
    char name[50];
    float marks[3];
    float average;
    char grade;
};

void calculateGrade(struct Student *s) {
    s->average = (s->marks[0] + s->marks[1] + s->marks[2]) / 3;
    if (s->average >= 90) s->grade = 'A';
    else if (s->average >= 75) s->grade = 'B';
    else if (s->average >= 60) s->grade = 'C';
    else s->grade = 'F';
}

void displayStudent(struct Student s) {
    printf("\nID: %d | Name: %s | Avg: %.2f | Grade: %c\n",
           s.id, s.name, s.average, s.grade);
}

int main() {
    int n, i;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student students[n];
    
    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("ID: "); scanf("%d", &students[i].id);
        printf("Name: "); scanf("%s", students[i].name);
        printf("Marks (3 subjects): ");
        scanf("%f %f %f", &students[i].marks[0], &students[i].marks[1], &students[i].marks[2]);
        calculateGrade(&students[i]);
    }
    
    printf("\n=== Student Records ===");
    for (i = 0; i < n; i++)
        displayStudent(students[i]);
    
    return 0;
}