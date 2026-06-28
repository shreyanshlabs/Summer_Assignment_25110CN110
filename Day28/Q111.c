#include <stdio.h>
#include <string.h>

struct Ticket {
    int ticketNo;
    char passengerName[50];
    char from[30];
    char to[30];
    char travelDate[15];
    float fare;
};

int main() {
    struct Ticket tickets[20];
    int count = 0, choice, tNo, i, found;
    int totalSeats = 50;
    int bookedSeats = 0;

    printf("====== Welcome to Ticket Booking System ======\n");

    do {
        printf("\n1. Book Ticket\n");
        printf("2. View All Bookings\n");
        printf("3. Search Ticket\n");
        printf("4. Cancel Ticket\n");
        printf("5. Available Seats\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (bookedSeats >= totalSeats) {
                    printf("Sorry! No seats available.\n");
                    break;
                }
                tickets[count].ticketNo = 1000 + count + 1;
                printf("Passenger Name: ");
                scanf(" %[^\n]", tickets[count].passengerName);
                printf("From: ");
                scanf("%s", tickets[count].from);
                printf("To: ");
                scanf("%s", tickets[count].to);
                printf("Travel Date (DD/MM/YYYY): ");
                scanf("%s", tickets[count].travelDate);
                tickets[count].fare = 500.0 + (count % 3) * 200;  // dynamic fare
                bookedSeats++;
                printf("\n===== Booking Confirmed =====\n");
                printf("Ticket No  : %d\n", tickets[count].ticketNo);
                printf("Passenger  : %s\n", tickets[count].passengerName);
                printf("From       : %s\n", tickets[count].from);
                printf("To         : %s\n", tickets[count].to);
                printf("Date       : %s\n", tickets[count].travelDate);
                printf("Fare       : Rs. %.2f\n", tickets[count].fare);
                count++;
                break;

            case 2:
                if (count == 0) {
                    printf("No bookings found!\n");
                    break;
                }
                printf("\n%-8s %-18s %-10s %-10s %-12s %-8s\n",
                       "TickNo", "Name", "From", "To", "Date", "Fare");
                printf("----------------------------------------------------------------\n");
                for (i = 0; i < count; i++) {
                    if (tickets[i].ticketNo != -1)
                        printf("%-8d %-18s %-10s %-10s %-12s Rs.%.2f\n",
                               tickets[i].ticketNo, tickets[i].passengerName,
                               tickets[i].from, tickets[i].to,
                               tickets[i].travelDate, tickets[i].fare);
                }
                break;

            case 3:
                printf("Enter Ticket Number: ");
                scanf("%d", &tNo);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (tickets[i].ticketNo == tNo) {
                        printf("\nTicket No  : %d\n", tickets[i].ticketNo);
                        printf("Passenger  : %s\n", tickets[i].passengerName);
                        printf("From → To  : %s → %s\n", tickets[i].from, tickets[i].to);
                        printf("Date       : %s\n", tickets[i].travelDate);
                        printf("Fare       : Rs. %.2f\n", tickets[i].fare);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Ticket not found!\n");
                break;

            case 4:
                printf("Enter Ticket Number to cancel: ");
                scanf("%d", &tNo);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (tickets[i].ticketNo == tNo) {
                        tickets[i].ticketNo = -1;  // mark as cancelled
                        bookedSeats--;
                        printf("Ticket cancelled successfully!\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Ticket not found!\n");
                break;

            case 5:
                printf("Total Seats  : %d\n", totalSeats);
                printf("Booked Seats : %d\n", bookedSeats);
                printf("Available    : %d\n", totalSeats - bookedSeats);
                break;

            case 6:
                printf("Thank you for using Ticket Booking System!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}