/* Student Name: Christian Seals
   U number: U56090851
   Program: Counselor Assignment
   Description: This program reads the total number of counselors and the counselors 
   already assigned, then finds and prints the counselor that hasn't been assigned.
*/

#include <stdio.h>

/* Function to find the unassigned counselor */
int search(int counselors[], int n) {
	int assigned[n + 1];  // markers for counselors 1 to n
	
	/* Intialize all markers to 0 */
	for (int i = 1; i <= n; i++) {
		assigned[i] = 0;
	}

	/* Mark the counselors that have already been assigned */
	for (int i  = 0; i < n - 1; i++) {
		int c = counselors[i];
		if (c >= 1 && c <= n) {
			assigned[c] = 1;
		}
	}

	/* Find the counselor that has not been assigned */
	for (int i = 1; i <= n; i++) {
		if (assigned[i] == 0) {
			return i;
		}
	}

	return -1; // should never happen
}

int main(void) {
	int n;

	/* Read number of counselors */
	printf("Enter number of counselors: ");
	scanf("%d", &n);

	int counselors[n - 1];

	/* Read counselors already assigned */
	printf("Enter counselors assigned: ");
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &counselors[i]);
	}

	/* Find the unassigned counselor */
	int missing = search(counselors, n);

	/* print result */
	printf("Counselor has not been assigned: %d\n", missing);

	return 0;
}


