#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    float a, b, result;

    do {
        printf("\n====== Menu-Driven Calculator ======\n");
        printf("1.  Addition\n");
        printf("2.  Subtraction\n");
        printf("3.  Multiplication\n");
        printf("4.  Division\n");
        printf("5.  Modulus\n");
        printf("6.  Power\n");
        printf("7.  Square Root\n");
        printf("8.  Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 6) {
            printf("Enter two numbers: ");
            scanf("%f %f", &a, &b);
        } else if (choice == 7) {
            printf("Enter a number: ");
            scanf("%f", &a);
        }

        switch (choice) {
            case 1:
                printf("Result: %.2f + %.2f = %.2f\n", a, b, a + b);
                break;
            case 2:
                printf("Result: %.2f - %.2f = %.2f\n", a, b, a - b);
                break;
            case 3:
                printf("Result: %.2f * %.2f = %.2f\n", a, b, a * b);
                break;
            case 4:
                if (b == 0) printf("Error: Division by zero!\n");
                else printf("Result: %.2f / %.2f = %.2f\n", a, b, a / b);
                break;
            case 5:
                printf("Result: %d %% %d = %d\n", (int)a, (int)b, (int)a % (int)b);
                break;
            case 6:
                printf("Result: %.2f ^ %.2f = %.2f\n", a, b, pow(a, b));
                break;
            case 7:
                if (a < 0) printf("Error: Cannot find sqrt of negative!\n");
                else printf("Result: sqrt(%.2f) = %.2f\n", a, sqrt(a));
                break;
            case 8:
                printf("Exiting Calculator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 8);

    return 0;
}
