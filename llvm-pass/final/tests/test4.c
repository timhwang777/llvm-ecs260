#include <stdio.h>

int main() {
  int numbers[4][3];
  for(int i = 0 ; i < 4 ; i++) {
    for(int j = 0 ; j < 4 ; j++){
      numbers[i][j] = i;
    }
  }
  return 0;
}