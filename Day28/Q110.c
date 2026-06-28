#include <stdio.h>
#include <string.h>

struct Account {
    int accNo;
    char name[50];
    char type[20];    // Savings / Current
    float balance;
};

void displayAccount(struct Account a) {
    printf("\n===== Account Details =====\n");
    printf("Account No : %d\n", a.accNo);
    printf("Name       : %s\n", a.name);
    printf("Type       : %s\n", a.type);
    printf("Balance    : Rs. %.2f\n", a.balance);
}

int main() {
    struct Account acc[10];
    int count = 0, choice, accNo, i, found;
    float amount;

    do {
        printf("\n====== Bank Account System ======\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. View All Accounts\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Account Number: ");
                scanf("%d", &acc[count].accNo);
                printf("Account Holder Name: ");
                scanf(" %[^\n]", acc[count].name);
                printf("Account Type (Savings/Current): ");
                scanf("%s", acc[count].type);
                printf("Initial Deposit: Rs. ");
                scanf("%f", &acc[count].balance);
                count++;
                printf("Account created successfully!\n");
                break;

            case 2:
                printf("Enter Account Number: ");
                scanf("%d", &accNo);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (acc[i].accNo == accNo) {
                        printf("Deposit Amount: Rs. ");
                        scanf("%f", &amount);
                        acc[i].balance += amount;
                        printf("Rs. %.2f deposited. New Balance: Rs. %.2f\n",
                               amount, acc[i].balance);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Account not found!\n");
                break;

            case 3:
                printf("Enter Account Number: ");
                scanf("%d", &accNo);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (acc[i].accNo == accNo) {
                        printf("Withdrawal Amount: Rs. ");
                        scanf("%f", &amount);
                        if (amount > acc[i].balance)
                            printf("Insufficient balance! Available: Rs. %.2f\n", acc[i].balance);
                        else {
                            acc[i].balance -= amount;
                            printf("Rs. %.2f withdrawn. Remaining: Rs. %.2f\n",
                                   amount, acc[i].balance);
                        }
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Account not found!\n");
                break;

            case 4:
                printf("Enter Account Number: ");
                scanf("%d", &accNo);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (acc[i].accNo == accNo) {
                        displayAccount(acc[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Account not found!\n");
                break;

            case 5:
                if (count == 0) {
                    printf("No accounts found!\n");
                } else {
                    printf("\n%-10s %-20s %-12s %-10s\n",
                           "Acc No", "Name", "Type", "Balance");
                    printf("--------------------------------------------------\n");
                    for (i = 0; i < count; i++)
                        printf("%-10d %-20s %-12s Rs.%-10.2f\n",
                               acc[i].accNo, acc[i].name,
                               acc[i].type, acc[i].balance);
                }
                break;

            case 6:
                printf("Thank you for banking with us!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}