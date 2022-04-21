#include <stdio.h>
#define SIZE 512

int main() {
  double sum, a[SIZE], b[SIZE];
  
  // Initialisation
  sum = 0.;
  for (size_t i = 0; i < SIZE; i++) {
    a[i] = i * 0.4;
    b[i] = i * 3.0;
  }

  // Calcul
  for (size_t i = 0; i < SIZE; i++)
    sum = sum + a[i]*b[i];

  printf("sum = %g\n", sum);
  return 0;
}