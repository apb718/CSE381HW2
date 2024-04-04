#include <iostream>

bool isPrime(int n) {
  // 2 is the smallest prime number
  if (n < 2) return false;
  if (n == 2) return true;

  for (int j = 2; j < n; j++) {
    if ( (n % j) == 0)
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
    exit(0);
}
