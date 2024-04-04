// Copyright Alec Byrd 2024
#include <iostream>
#include <sstream>

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

//  GPT Generated function
bool isInteger(const std::string& input) {
    std::istringstream stream(input);
    int n;
    return (stream >> n) && (stream.eof());
}

int serialExecute(int max) {
  int primeCount = 0;
  for (int i = 0; i < max; i++) {
    if (isPrime(i)) {
      primeCount++;
    }
  }
  return primeCount;
}

int inefficientMultithread(int max) {
  int primeCount = 0;
  return primeCount;
}

int efficientMultithread(int max) {
  int primeCount = 0;
  return primeCount;
}
int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cout << "Usage:  primesMT maxToCheck mode" <<
    std::endl;
    exit(0);}
  if (!isInteger(argv[1]) || !isInteger(argv[2])) {
    std::cout << "Error: arguments must be integers" <<
    std::endl;
    exit(0);}
  int topValue = std::stoi(argv[1]);
  int option = std::stoi(argv[2]);
  int returnedPrimeCount = 0;
  switch (option) {
    case 0:
      returnedPrimeCount = serialExecute(topValue);
      break;
    case 1:
      returnedPrimeCount = inefficientMultithread(topValue);
      break;
    case 2:
      returnedPrimeCount = efficientMultithread(topValue);
      break;}
  std::cout << "Found " << returnedPrimeCount
    << " prime numbers < " << topValue << std::endl;

  exit(0);
}
