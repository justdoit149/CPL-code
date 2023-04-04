#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

bool IsPrime(int number);

int main() {
  int max = 0;
  scanf("%d", &max);

  for (int number = 2; number <= max; number++) {
    if (IsPrime(number)) {
      printf("%d ", number);
    }
  }

  return 0;
}

bool IsPrime(int number) {
  for (int i = 2; i * i <= number; i++) {
    if (number % i == 0) {
      return false;
    }
  }

  return true;
}

/*
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int main() {
  int max = 0;
  scanf("%d", &max);

  for (int number = 2; number <= max; number++) {
    // decide whether number is a prime number
    bool is_prime = true;
    for (int i = 2; i * i <= number; i++) {
      if (number % i == 0) {
        is_prime = false;
        break;
      }
    }

    if (is_prime) {
      printf("%d ", number);
    }
  }

  return 0;
}
*/