#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

bool IsEqual(double x, double y);

int main() {
  printf("%d\n", IsEqual(DBL_MAX, DBL_MAX - 100));

  printf("%.50f\n", DBL_MAX - (DBL_MAX - 100));

  return 0;
}

bool IsEqual(double x, double y) {
  return fabs(x - y) <= DBL_EPSILON;
}