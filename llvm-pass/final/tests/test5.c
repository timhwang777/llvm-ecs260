#include <stdio.h>

int main() {
  int numbers[3][3][2];
  for(int i = 0 ; i < 3 ; i++) {
    for(int j = 0 ; j < 3 ; j++){
      for(int k = 0 ; k < 3 ; k++){
        numbers[i][j][k] = i;
      }
    }
  }
  return 0;
}