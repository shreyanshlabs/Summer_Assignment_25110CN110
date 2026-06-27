#include <stdio.h>

int main() {
    char name[50];
    float basic, hra, da, ta, gross, pf, tax, net;
    
    printf("=== Salary Management System ===\n");
    printf("Employee Name: "); scanf("%s", name);
    printf("Basic Salary: "); scanf("%f", &basic);
    
    hra = 0.20 * basic;
    da  = 0.50 * basic;
    ta  = 0.10 * basic;
    gross = basic + hra + da + ta;
    pf  = 0.12 * basic;
    tax = (gross > 25000) ? 0.10 * gross : 0;
    net = gross - pf - tax;
    
    printf("\n====== Salary Slip for %s ======\n", name);
    printf("Basic Salary : Rs. %.2f\n", basic);
    printf("HRA (20%%)    : Rs. %.2f\n", hra);
    printf("DA  (50%%)    : Rs. %.2f\n", da);
    printf("TA  (10%%)    : Rs. %.2f\n", ta);
    printf("Gross Salary : Rs. %.2f\n", gross);
    printf("PF  (12%%)    : Rs. %.2f\n", pf);
    printf("Tax          : Rs. %.2f\n", tax);
    printf("Net Salary   : Rs. %.2f\n", net);
    
    return 0;
}