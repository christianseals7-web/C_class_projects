

#include <stdio.h>

/* 
   The compute function performs symmetric addition on array a1 and stores 
   results in a2. It uses pointer arithmetic to access elements 
   from both ends of the input array simultaneously.
*/

void compute(int *a1, int n1, int *a2, int n2) {
	int *left_ptr = a1;            // Pointer to the start of input
	int *right_ptr = a1 + n1 - 1;  // Pointer to the end of input 
	int *out_ptr = a2;             // Pointer to the output array

	/* Move pointers inward, adding pairs until they meet or cross */
	while(left_ptr < right_ptr) {
		/* Add the two symmetric elements and store in output */
		*out_ptr = * left_ptr + *right_ptr;
		
		/* Advance pointers using arithmetic */
		out_ptr++;
		left_ptr++;
		right_ptr--;
	}

	/* If array length was odd, pointers meet at the middle element */
	if(left_ptr == right_ptr) {
		*out_ptr = *left_ptr;
	}
}

int main() {
	int input_size;

	/* Get the length of the intial array */
	printf("Enter the length of the array: ");
	if(scanf("%d", &input_size) != 1) {
		return 0;
	}

	int input_arr[input_size];
	/* Input elements using standard subscripting */
	printf("Enter the elements of the array: ");
	for(int i = 0; i < input_size; i++) {
		scanf("%d", &input_arr[i]);
	}

	/* Calculate output length: pairs + possible middle element */
	int output_size = (input_size / 2) + (input_size % 2);
	int output_arr[output_size];

	/* Process the data using the pointer based function */
	compute(input_arr, input_size, output_arr, output_size);
	
	/* Output the resulting transformed array using standard subscripting */
	printf("Output: ");
	for(int i = 0; i < output_size; i++) {
		printf("%d%s", output_arr[i], (i == output_size - 1) ? "" : " ");
	}
	printf("\n");

	return 0;
}	
