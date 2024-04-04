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

void serialExecute(int max) {
  int primeCount = 0;
  for (int i = 0; i < max; i++) {
    if (isPrime(i)) {
      primeCount++;
    }
  }
  std::cout << "Prime Count: " << primeCount << std::endl;
}

void inefficientMultithread(int max) {
  
}

void efficientMultithread(int max) {
}
int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cout << "Usage:  primesMT maxToCheck mode" << std::endl;
    exit(0);
  }
  if (!isInteger(argv[1]) || !isInteger(argv[2])) {
    std::cout << "Error: arguments must be integers" << std::endl;
  }
  int option = std::stoi(argv[1]);
  int topValue = std::stoi(argv[2]);
  switch (option) {
    case 0:
      serialExecute(topValue);
    case 1:
      inefficientMultithread(topValue);
    case 2:
      efficientMultithread(topValue);
  }

  exit(0);
}
