#include <stdio.h>

int main() {
    float balance = 10000.0;
    int choice;
    float amount;
    int pin, enteredPin = 1234;
    
    printf("=== ATM Simulation ===\n");
    printf("Enter PIN: ");
    scanf("%d", &pin);
    
    if (pin != enteredPin) {
        printf("Invalid PIN! Access Denied.\n");
        return 0;
    }
    
    do {
        printf("\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Current Balance: Rs. %.2f\n", balance);
                break;
            case 2:
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                balance += amount;
                printf("Deposited Rs. %.2f. New Balance: Rs. %.2f\n", amount, balance);
                break;
            case 3:
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);
                if (amount > balance)
                    printf("Insufficient balance!\n");
                else {
                    balance -= amount;
                    printf("Withdrawn Rs. %.2f. Remaining: Rs. %.2f\n", amount, balance);
                }
                break;
            case 4:
                printf("Thank you for using ATM!\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (choice != 4);
    
    return 0;
}