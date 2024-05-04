#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Preprocessor

// Data Structures
enum { IMG_SIZE = 8 };

struct image {
  char pixels[IMG_SIZE][IMG_SIZE];
};

// Prototypes
static void flood_fill(struct image *const img, int x, int y, char find,
                       char replace);

// Function main begins program execution.
int main(void) {
  printf("Hello, world!");
  exit(EXIT_SUCCESS);
}
