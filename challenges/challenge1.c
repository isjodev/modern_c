/* Challenge 1: Sequential sorting algorithms.
 * merge_sort(with recursion)
 * quick_sort(with recursion)
 * on arrays with sort keys such as double or strings
 * to your liking.  */

/* TODO: Implement quick_sort for both strings and doubles.
 * TODO: Provide error handing.
 * TODO: Implement merge_sort().  */

// Preprocessor.
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// User defined headers?
// merge_sort.h
// quick_sort.h

// Number of elements in array.
#define LEN 5

// Function prototypes.
int *init_int_array(int len);
void fill_int_array(int *array, int len);
void print_int_array(int *array, int len);
void swap(int *, int *);
int partition(int *array, int start, int end);
void quick_sort(int *array, int start, int end);

int main(void) {
  // Initialize and fill integer array with LEN values.
  int *array = init_int_array(LEN);
  fill_int_array(array, LEN);

  // Print Array
  print_int_array(array, LEN);

  // Sort Array
  quick_sort(array, 0, LEN - 1);

  // Print Array
  print_int_array(array, LEN);
  return 0;
}

/* init_int_array takes takes intger value len and dynamically allocates
 * an array of length len, and returns a pointer to array. */
int *init_int_array(int len) {
  // Dynamically allocate array.
  int *int_array = malloc(sizeof(int) * len);
  return int_array;
}

/* fill_int_array randomly generates integers and populates array. */
void fill_int_array(int *array, int len) {
  // Seed random.
  srand(time(NULL));

  // Loop over array.
  for (size_t i = 0; i < len; i++) {
    // Random integer value between 0 - 100
    int rand_val = rand() % 100;
    array[i] = rand_val;
  }
}

/* print_int_array loops over the length of an array and prints the
 * value at each address. */
void print_int_array(int *array, int len) {
  for (size_t i = 0; i < len; i++) {
    printf("%d ", *(array + i));
  }
  printf("\n");
}

// Swap two pointers.
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/* partition takes an array, start, and end index,
 * swaps any values which are less than the pivot value,
 * then returns the array index after the pivot value. */
int partition(int *array, int start, int end) {
  // Use last element in arry as pivot value.
  int pivot = array[end];

  // Subarray begins with element behind first value.
  int pivot_idx = (start - 1);

  // Loop through array, swapping any values which are less than or equal
  // to the pivot value.
  for (int i = start; i < end; i++) {
    if (array[i] <= pivot) {
      // Increment pivot index.
      pivot_idx++;
      swap(&array[i], &array[pivot_idx]);
    }
  }

  // Swap final value with pivot value.
  swap(&array[pivot_idx + 1], &array[end]);

  // Return index of final swap position.
  return (pivot_idx + 1);
}

/* quick_sort takes an array, a starting index, and a final index.
 * If the starting index is less than the final index,
 * partition the array into subarrays and sort each subarray. */
void quick_sort(int *array, int start, int end) {
  // TODO: Error handling.
  if (start < end) {
    int pivot_idx = partition(array, start, end);
    quick_sort(array, start, pivot_idx - 1);
    quick_sort(array, pivot_idx + 1, end);
  }
}
