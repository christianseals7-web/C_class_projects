

#include <stdio.h>
#include <stdlib.h>

/* Macro definitions for AC rental pricing */
#define AC1_FIRST_DAY 50
#define AC1_DAILY_RATE 30
#define AC1_WEEKLY_MAX 160
#define AC2_FIRST_DAY 60
#define AC2_DAILY_RATE 35
#define AC2_WEEKLY_MAX 200
#define AC3_FIRST_DAY 80
#define AC3_DAILY_RATE 50
#define AC3_WEEKLY_MAX 280
#define AC4_FIRST_DAY 200
#define AC4_DAILY_RATE 120
#define AC4_WEEKLY_MAX 550

int main() {
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

    /* Assign pricing based on selection */
    switch (ac_selection) {
        case 1:
            first_day_charge = AC1_FIRST_DAY;
            daily_charge = AC1_DAILY_RATE;
            weekly_max_charge = AC1_WEEKLY_MAX;
            break;
        case 2:
            first_day_charge = AC2_FIRST_DAY;
            daily_charge = AC2_DAILY_RATE;
            weekly_max_charge = AC2_WEEKLY_MAX;
            break;
        case 3:
            first_day_charge = AC3_FIRST_DAY;
            daily_charge = AC3_DAILY_RATE;
            weekly_max_charge = AC3_WEEKLY_MAX;
            break;
        case 4:
            first_day_charge = AC4_FIRST_DAY;
            daily_charge = AC4_DAILY_RATE;
            weekly_max_charge = AC4_WEEKLY_MAX;
            break;
    }

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

