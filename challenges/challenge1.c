/* Challenge 1: Sequential sorting algorithms.
 * merge_sort(with recursion)
 * quick_sort(with recursion)
 * on arrays with sort keys such as double or strings
 * to your liking.  */

// Preprocessor.
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// User defined headers.
// merge_sort.h
// quick_sort.h

// Number of elements in array.
#define LEN 100

// Function prototypes.
int *init_int_array(int len);
void fill_int_array(int *array, int len);
void print_int_array(int *array, int len);

int main(void) {
  int *array = init_int_array(LEN);
  fill_int_array(array, LEN);

  // Sort

  // Print
  print_int_array(array, LEN);
  return 0;
}

int *init_int_array(int len) {
  int *int_array = malloc(sizeof(int) * len);
  return int_array;
}

void fill_int_array(int *array, int len) {
  srand(time(NULL));
  for (size_t i = 0; i < len; i++) {
    // Random integer value between 0 - 100
    int rand_val = rand() % 100;
    *(array + i) = rand_val;
  }
}

void print_int_array(int *array, int len) {
  for (size_t i = 0; i < len; i++) {
    printf("%d ", *(array + i));
  }
}
