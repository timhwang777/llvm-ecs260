#include <stdio.h>

int main() {
  double numbers[3][2];
  for(int i = 0 ; i < 4 ; i++) {
    for(int j = 0 ; j < 2 ; j++){
      numbers[i][j] = i + 0.1;
    }
  }
  return 0;
}