

#include <stdio.h>

/*
  The find_elements function identifies unique elements from two arrays and 
  stores them in a third. It uses pointer arithmetic to traverse the array
  without using subscripting [].
*/

int find_elements(int *a, int n1, int *b, int n2, int *c) {
	int count = 0;
	int *ptr_a, *ptr_b, *ptr_result;

	/* Add all elements from the first array to the result array */
	for(ptr_a = a; ptr_a < a + n1; ptr_a++) {
		*(c + count) = *ptr_a;
		count++;
	}

	/* Iterate through the second array to find elements not already in c */
	for(ptr_b = b; ptr_b < b + n2; ptr_b++) {
		int already_exists = 0; 
    

		/* Check current element against all elements currently in array c */
		for(ptr_result = c; ptr_result < c + count; ptr_result++) {
			if(*ptr_b == *ptr_result) {
				already_exists =1;
				break;
			}
		}

		/* If element is unique, add it to array c using pointer arithmetic */
		if(!already_exists) {
			*(c + count) = *ptr_b;
			count++;
		}
	}

	/* Return the final number of unique elements stored in c */
	return count;
}

int main() {
	int len1, len2;

       	 /* Input collection for the first array */
         printf("Enter the length of the first array: ");
         scanf("%d", &len1);
         int array_a[len1];
       	 printf("Enter elements in the first array: ");
       	 for (int i = 0; i < len1; i++) {
       	 scanf("%d", &array_a[i]);
       	 }

       	 /* Input collection for the second array */
	 printf("Enter the length of the second array: ");
   	 scanf("%d", &len2);
	 int array_b[len2];
	 printf("Enter elements in the second array: ");
   	 for (int i = 0; i < len2; i++) {
        	scanf("%d", &array_b[i]);
   	 }

	 /* Prepare result array and call the processing function */
	int array_c[len1 + len2];
	int total_distinct = find_elements(array_a, len1, array_b, len2, array_c);

	/* Display the combined list of students */
	printf("Output: ");
	for(int i = 0; i < total_distinct; i++) {
		printf("%d%s", array_c[i], (i == total_distinct - 1) ? "" : " ");
	}
	printf("\n");

	return 0;
}  

