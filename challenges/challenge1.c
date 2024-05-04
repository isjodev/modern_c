/* Challenge 1: Sequential sorting algorithms.
 * merge_sort(with recursion)
 * quick_sort(with recursion)
 * on arrays with sort keys such as double or strings
 * to your liking.  */

/* TODO: Implement quick_sort for both strings and doubles.
 * TODO: Provide error handing.
 * TODO: Implement merge_sort().  */

// Preprocessor.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 

// Number of elements in array.
#define LEN 10

// Function prototypes.
int *init_int_array(int len);
void fill_int_array(int *array, int len);
void print_int_array(int *array, int len);
void swap(int *, int *);
int partition(int *array, int start, int end);
void quick_sort(int *array, int start, int end);
void merge_sort(int *, int, int); 
void merge(int*, int, int, int); 
int get_midpoint(int, int); 

int main(void) {
  // Seed random.
  srand(time(NULL));

  // Initialize and fill integer array with LEN values.
  int *array1 = init_int_array(LEN);
  int *array2 = init_int_array(LEN); 
  fill_int_array(array1, LEN);
  fill_int_array(array2, LEN);

  // Print Array
  printf("Array1:\n"); 
  print_int_array(array1, LEN);
  printf("Array2:\n"); 
  print_int_array(array2, LEN);

  // Sort Array
  quick_sort(array1, 0, LEN - 1);
  merge_sort(array2, 0, LEN - 1); 

  // Print Array
  printf("Array1:\n"); 
  print_int_array(array1, LEN);
  printf("Array2:\n"); 
  print_int_array(array2, LEN);

  free(array1); 
  free(array2); 
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

int get_midpoint(int start, int end) {
  return floor(start + end) / 2; 
}

void merge(int* array, int start, int mid, int end)  {
  int len_left = mid - start + 1; 
  int len_right = end - mid; 

  int* left_subarray = malloc(sizeof(int) * len_left); 
  int* right_subarray = malloc(sizeof(int)* len_right); 

  for (int i = 0; i < len_left; i++) {
    left_subarray[i] = array[start + i]; 
  }

  for (int j = 0; j < len_right; j++) {
    right_subarray[j] = array[mid + j + 1]; 
  }

  int i = 0; 
  int j = 0; 
  int k = start; 

  while (i < len_left && j < len_right) {
    if (left_subarray[i] <= right_subarray[j]) {
      array[k] = left_subarray[i]; 
      i++; 
    } else {
      array[k] = right_subarray[j]; 
      j++; 
    }
    k++; 
  }

  while (i < len_left) {
    array[k] = left_subarray[i]; 
    i++; 
    k++; 
  }

  while (j < len_right) {
    array[k] = right_subarray[j]; 
    j++; 
    k++; 
  }

  free(left_subarray); 
  free(right_subarray); 
}

void merge_sort(int* array, int start,  int end) {
  if (start >= end) {
    return; 
  }

  int mid = get_midpoint(start, end); 
  merge_sort(array, start, mid); 
  merge_sort(array, mid + 1, end); 
  merge(array, start, mid, end); 
}
