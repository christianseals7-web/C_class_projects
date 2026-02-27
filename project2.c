

#include <stdio.h>

int main(void) {
	char current_char;
	int ascii_value;

	printf("Enter 1 or more characters then ENTER:\n");
	printf("(NOTE: a character # will exit the program):\n");

	do {
		// Read characters until newline or '#' is encountered
		while ((current_char = getchar()) != '\n' && current_char != '#') {
			ascii_value = (int)current_char;

			// Skip printing for '#' and '\n' as specified
			printf("\nYou typed: '%c' (ASCII %d)\n", current_char, ascii_value);

			// Classify the character and perform conversion if needed
			if (ascii_value >= 65 && ascii_value <= 90) {
				printf("Class: Uppercase Letter\n");
				// Convert to Lowercase (add 32 to ASCII value)
				char converted_char = current_char + 32;
				printf("Converted to: '%c'\n", converted_char);
			}
			else if (ascii_value >= 97 && ascii_value <= 122) {
				printf("Class: Lowercase Letter\n");
				// Convert to uppercase (subtract 32 from ASCII value)
				char converted_char = current_char - 32;
				printf("Converted to: '%c'\n", converted_char);
			}
			else if (ascii_value >= 48 && ascii_value <= 57) {
				printf("Class: Digit\n");
				printf("No conversion done\n");
			}
			else if (ascii_value >= 32 && ascii_value <= 126) {
				//  This covers printable symbols (not letters or digits) 
				printf("Class: Printable Symbol\n");
				printf("No conversion done\n");
			}
			else {
				// Non-printable characters (ASCII < 32 OR >= 127)
				printf("Class: Non-printable or extended ASCII\n");
				printf("No conversion done\n");
			}
		}

		//  If we broke out of the inner loop because of '#', exit the outer loop 
		if (current_char == '#') {
			break;
		}

		// If we got here, we hit newline, so prompt for more input
		printf("\nEnter 1 or more characters then ENTER:\n");
		printf("(NOTE: a character # will exit the program):\n");
	
	} while (1); // Infinite loop that breaks when '#' is encountered

	return 0;
}
