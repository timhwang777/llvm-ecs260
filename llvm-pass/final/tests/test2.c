#include <stdio.h>

int main() {
  int numbers[3][2];
  for(int i = 0 ; i < 4 ; i++) {
    for(int j = 0 ; j < 2 ; j++){
      numbers[i][j] = i;
    }
  }
  return 0;
}