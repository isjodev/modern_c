#include <stdlib.h> 
#include <stdio.h> 
#include <time.h> 

int main(void) {
  srand(time(NULL)); 
  int a = 100; 
  
  float foobar = (float)rand()/(float)(RAND_MAX/a); 
  printf("%f\n", foobar); 

  printf("float: %zu\n", sizeof(float)); 
  printf("int: %zu\n", sizeof(int)); 
  printf("char: %zu\n", sizeof(char)); 
  return 0; 
}
