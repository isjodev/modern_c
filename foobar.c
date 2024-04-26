#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *message = "well you see. they point to things";
  int len = strlen(message);

  char *messagePtr;
  messagePtr = message;

  // Point my fucking balls into your mouth.
  // :w
  while (*messagePtr != '\0') {
    printf("%c", *messagePtr);
    ++messagePtr;
  }

  exit(EXIT_SUCCESS);
}
