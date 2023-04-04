/**
 * Recursively computing the greatest common divisor of two integers
 *
 * Euclidean algorithm:
 * gcd(a, b) = gcd(b, a % b)
 */

#include <stdio.h>

int GCD(int a, int b);

int main() {
  int a = 0;
  int b = 0;
  scanf("%d %d", &a, &b);

  printf("GCD(%d, %d) = %d\n", a, b, GCD(a, b));

  return 0;
}

// gcd(130, 124) = 2
// gcd(414, 662) = 2

int GCD(int a, int b) {
  if (b == 0) {
    return a;
  }

  return GCD(b, a % b);
}