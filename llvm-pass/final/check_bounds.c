#include <stdio.h>

/***
** Implement the function below. Function check_bounds takes as input
** the size of the array being accessed, the index of the accessed
** element, and the line number and file in which this access
** occurs. If the access is out of bounds, then the function prints an
** error message.
***/
void check_bounds(__int64_t sz, __int64_t index, __int64_t ln, char* filename) {
  printf("Array size: %ld\n", sz);
  printf("Index: %ld\n", index);
  //printf("%ld\n", ln);
  //printf("%s\n", filename);
  //printf("Out-of-Bounds Checking...\n");

  if (index >= sz || index < 0) {
    printf("%s:%ld: Array Out of Bounds Error.\n", filename, ln);
  }
  return;
}
