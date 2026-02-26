/* Student Name: Christian Seals
   U number: U56090851
   Program: AC Rental Cost Calculator
   Description: This program calculates the rental charge for different AC units 
   based on user selection and number of rental days. It applies first day charges, 
   daily rates, weekly maximums, and validates user input.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    /* Arrays for AC rental pricing */
    int firstDay[4] = {50, 60, 80, 200};
    int dailyRate[4] = {30, 35, 50, 120};
    int weeklyMax[4] = {160, 200, 280, 550};

    /* Variables for user input and calculation */
    int ac_selection;        // User's AC selection
    int rental_days;         // Number of rental days
    int first_day_charge = 0;    // Flat charge for first day
    int daily_charge = 0;        // Daily charge after first day
    int weekly_max_charge = 0;   // Maximum charge per week
    int total_charge = 0;        // Total rental cost

    /* Prompt user for AC selection */
    printf("Please select from four types of AC: 1, 2, 3, and 4\n");
    printf("Enter selection: ");
    scanf("%d", &ac_selection);

    /* Validate AC selection */
    if (ac_selection < 1 || ac_selection > 4) {
        printf("Invalid selection. Select from 1 to 4.\n");
        return 0;
    }

    /* Prompt user for number of rental days */
    printf("Enter days: ");
    scanf("%d", &rental_days);

    /* Validate number of days */
    if (rental_days < 0) {
        printf("Invalid days.\n");
        return 0;
    }

    /* Assign pricing based on selection using arrays */
    int index = ac_selection - 1;
    first_day_charge = firstDay[index];
    daily_charge = dailyRate[index];
    weekly_max_charge = weeklyMax[index];
          

    /* Calculate full weeks and remaining days */
    int full_weeks = rental_days / 7;
    int remaining_days = rental_days % 7;

    /* Charge for full weeks */
    total_charge = full_weeks * weekly_max_charge;

    /* Charge for remaining days */
    if (remaining_days > 0) {
        int partial_charge;
        /* First day charge applies only if total rental <= 7 days */
        if (rental_days <= 7) {
            partial_charge = first_day_charge + (remaining_days - 1) * daily_charge;
        } else {
            partial_charge = remaining_days * daily_charge;
        }

        /* Cap charge at weekly maximum */
        if (partial_charge > weekly_max_charge) {
            partial_charge = weekly_max_charge;
        }
        total_charge += partial_charge;
    }

    /* Display final rental charge */
    printf("Charge($): %d\n", total_charge);

    return 0;
}

