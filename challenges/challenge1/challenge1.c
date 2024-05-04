/* Challenge 1: Sequential sorting algorithms.
 * merge_sort(with recursion)
 * quick_sort(with recursion)
 * on arrays with sort keys such as double or strings
 * to your liking.  */

// TODO: Break into header fifles 

// Preprocessor.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Number of elements in array.
#define LEN 10

// Function prototypes.
int *int_init_array(int);
void int_fill_array(int *, int);

float *float_init_array(int);
void float_fill_array(float *, int);

char* char_init_array(int); 
void char_fill_array(char*, int); 

void int_print_array(int *, int);
void float_print_array(float*, int); 
void char_print_array(char*, int); 

void int_swap(int *, int *);
int int_partition(int *, int, int);
void int_quick_sort(int *, int, int);
void int_merge_sort(int *, int, int);
void int_merge(int *, int, int, int);

int get_midpoint(int, int);

void float_swap(float*, float*); 
int float_partition(float*, int, int); 
void float_quick_sort(float*, int, int); 
void float_merge_sort(float*, int, int); 
void float_merge(float*, int, int, int); 

void char_swap(char*, char*); 
int char_partition(char*, int, int); 
void char_quick_sort(char*, int, int); 
void char_merge_sort(char*, int, int); 
void char_merge(float*, int, int, int); 

int main(void) {
  // Seed random.
  srand(time(NULL));

  // Initialize and fill integer array with LEN values.
  int *array1 = int_init_array(LEN);
  int *array2 = int_init_array(LEN);
  float* array3 = float_init_array(LEN); 
  float* array4 = float_init_array(LEN); 
  char* array5 = char_init_array(LEN); 
  char* array6 = char_init_array(LEN); 
  int_fill_array(array1, LEN);
  int_fill_array(array2, LEN);
  float_fill_array(array3, LEN); 
  float_fill_array(array4, LEN); 
  char_fill_array(array5, LEN); 
  char_fill_array(array6, LEN);

  // Print Array
  printf("Array1:\n");
  int_print_array(array1, LEN);
  printf("Array2:\n");
  int_print_array(array2, LEN);
  printf("Array3:\n"); 
  float_print_array(array3, LEN); 
  printf("Array4:\n"); 
  float_print_array(array4, LEN); 
  printf("Array5:\n"); 
  char_print_array(array5, LEN); 
  printf("Array6:\n"); 
  char_print_array(array6, LEN); 

  // Sort Array
  int_quick_sort(array1, 0, LEN - 1);
  int_merge_sort(array2, 0, LEN - 1);
  float_quick_sort(array3, 0, LEN - 1); 
  float_merge_sort(array4, 0, LEN - 1); 
  char_quick_sort(array5, 0, LEN - 1); 
  char_merge_sort(array6, 0,  LEN - 1); 

  // Print Array
  printf("Array1:\n");
  int_print_array(array1, LEN);
  printf("Array2:\n");
  int_print_array(array2, LEN);
  printf("Array3:\n"); 
  float_print_array(array3, LEN); 
  printf("Array4:\n"); 
  float_print_array(array4, LEN); 
  printf("Array5:\n"); 
  char_print_array(array5, LEN); 
  printf("Array6:\n"); 
  char_print_array(array6, LEN); 

  free(array1);
  free(array2);
  free(array3);
  free(array4);
  free(array5);
  free(array6);

  return 0;
}

/* int_init_array takes takes intger value len and dynamically allocates
 * an array of length len, and returns a pointer to array. */
int *int_init_array(int len) {
  // Dynamically allocate array.
  int *int_array = malloc(sizeof(int) * len);
  return int_array;
}

/* int_fill_array randomly generates integers and populates array. */
void int_fill_array(int *array, int len) {

  // Loop over array.
  for (size_t i = 0; i < len; i++) {
    // Random integer value between 0 - 100
    int rand_val = rand() % 100;
    array[i] = rand_val;
  }
}

float *float_init_array(int len) {
  float *array = malloc(sizeof(float) * len);
  return array;
}

void float_fill_array(float *array, int len) {
  int a = 100;
  for (int i = 0; i < len; i++) {
    float foobar = (float)rand() / (float)(RAND_MAX / a);
    array[i] = foobar;
  }
}

/* print_int_array loops over the length of an array and prints the
 * value at each address. */
void int_print_array(int *array, int len) {
  for (size_t i = 0; i < len; i++) {
    printf("%d ", *(array + i));
  }
  printf("\n");
}

void float_print_array(float *array, int len) {}

// Swap two pointers.
void int_swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/* partition takes an array, start, and end index,
 * swaps any values which are less than the pivot value,
 * then returns the array index after the pivot value. */
int int_partition(int *array, int start, int end) {
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
      int_swap(&array[i], &array[pivot_idx]);
    }
  }

  // Swap final value with pivot value.
  int_swap(&array[pivot_idx + 1], &array[end]);

  // Return index of final swap position.
  return (pivot_idx + 1);
}

/* quick_sort takes an array, a starting index, and a final index.
 * If the starting index is less than the final index,
 * partition the array into subarrays and sort each subarray. */
void int_quick_sort(int *array, int start, int end) {
  // TODO: Error handling.
  if (start < end) {
    int pivot_idx = int_partition(array, start, end);
    int_quick_sort(array, start, pivot_idx - 1);
    int_quick_sort(array, pivot_idx + 1, end);
  }
}

int int_get_midpoint(int start, int end) { return floor(start + end) / 2; }

void int_merge(int *array, int start, int mid, int end) {
  int len_left = mid - start + 1;
  int len_right = end - mid;

  int *left_subarray = malloc(sizeof(int) * len_left);
  int *right_subarray = malloc(sizeof(int) * len_right);

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

void int_merge_sort(int *array, int start, int end) {
  if (start >= end) {
    return;
  }

  int mid = int_get_midpoint(start, end);
  int_merge_sort(array, start, mid);
  int_merge_sort(array, mid + 1, end);
  int_merge(array, start, mid, end);
}

void float_swap(float* a, float* b) {
  float temp = *a; 
  *a = *b; 
  *b = temp; 
}

int float_partition(float* array, int start, int end) {
  float pivot = array[end]; 
  int pivot_idx = (start - 1); 

  for (int i = start; i < end; i++) {
    if (array[i] <= pivot) {
      pivot_idx++; 
      float_swap(&array[i], &array[pivot_idx]);
    }
  }
  float_swap(&array[pivot_idx + 1], &array[end]); 
  return (pivot_idx + 1); 
}

void float_quick_sort(float* array, int start, int end) {
  if (start < end) {
    int pivot_idx = float_partition(array, start, end); 
    float_quick_sort(array, start, pivot_idx - 1); 
    float_quick_sort(array, pivot_idx + 1, end); 
  }
}

void float_merge(float *array, int start, int mid, int end) {
  int len_left = mid - start + 1;
  int len_right = end - mid;

  float *left_subarray = malloc(sizeof(float) * len_left);
  float *right_subarray = malloc(sizeof(float) * len_right);

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

void float_merge_sort(float* array, int start, int end) {
  if (start >= end) {
    return;
  }

  int mid = int_get_midpoint(start, end);
  float_merge_sort(array, start, mid);
  float_merge_sort(array, mid + 1, end);
  float_merge(array, start, mid, end);
}

void char_swap(char* a, char* b) {
  char temp = *a; 
  *a = *b; 
  *b = temp; 
}

int char_partition(char* array, int start, int end)  {
  return 1; 
}

void char_quick_sort(char* array, int start,int end) {

}

void char_merge_sort(char* array, int start, int end) {

}

void char_merge(float* array, int start, int mid, int end) {

}
