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

// User defined headers?
// merge_sort.h
// quick_sort.h

// Number of elements in array.
#define LEN 10

// Function prototypes.
int *init_int_array(int len);
void fill_int_array(int *array, int len);
void print_int_array(int *array, int len);
void swap(int *, int *);
void partition(void);
void quick_sort(void);
void merge_sort(void);

int main(void) {
  int *array = init_int_array(LEN);
  fill_int_array(array, LEN);
  // int n = sizeof(array) / sizeof(array[0]);

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

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Input: Array, start, end
void partition(void) {
  // pivot = array[end]
  // pivot_idx = start
  // loop idx from start to end
  //   if array[index] <= pivot_value
  //     swap(array[index], array[pivot_idx])
  //     pivot_idx++
  // return pivot_idx - 1
}

void quick_sort(void) {
  // if start >= end
  //   return
  // pivot_idx = partition(array, start, end)
  // quick_sort(array, start, pivot_idx - 1)
  // quick_sort(aray, pivot_idx + 1, end)
}

void merge_sort(void) {}
