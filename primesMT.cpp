// Copyright Alec Byrd 2024
#include <iostream>
#include <sstream>
#include <thread>
#include <future>
#include <vector>
#include <numeric>
using std::thread;
bool isPrime(int n) {
  // 2 is the smallest prime number
  if (n < 2) return false;
  if (n == 2) return true;

  for (int j = 2; j < n; j++) {
    if ( (n % j) == 0)
      return false;
  }
  // std::cout << n << "is prime" << std::endl;
  return true;
}

void fillVector(std::vector<size_t>& vec1,
  std::vector<size_t>& vec2, int& max) {
  for (int i=0; i< max; i+=4) {
    if (i < max) vec1.push_back(i);
    if (i+1 < max) vec1.push_back(i+1);
    if (i+2 < max) vec2.push_back(i+2);
    if (i+3 < max) vec2.push_back(i+3);
  }
}

void checkTwo(int i, int j, int& accum) {
  if (isPrime(i)) {
    accum++;
  }
  if (isPrime(j)) {
    accum++;
  }
}

void checkPrimeVector(std::vector<size_t>& vec, int& accum) {
  for (auto& item : vec) {
    if (isPrime(item)) accum++;
  }
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
  int total = 0;
  for (int i = 0; i < max; i+=4) {
    int i1, i2, j1, j2 = 0;
    int accum1 = 0;
    int accum2 = 0;
    i1 = i;
    if (i+1 < max) {
      i2 = i+1;
    }
    if (i+2 < max) {
      j1 = i+2;
    }
    if (i+3 < max) {
     j2 = i+3;
    }
    // std::cout << i1 << " " << i2 << " " << j1 << " " << j2 << std::endl;
    thread th1 = thread(checkTwo, std::ref(i1), std::ref(i2), std::ref(accum1));
    thread th2 = thread(checkTwo, std::ref(j1), std::ref(j2), std::ref(accum2));

    // std::cout << accum1 << " " << accum2 << std::endl;
    th1.join();
    th2.join();
    total += accum1 + accum2;
  }
  return total;
}

int efficientMultithread(int max) {
  int t1Count = 0;
  int t2Count = 0;
  // std::cout << "Max: " << max << std::endl;
  std::vector<size_t> vec1, vec2;
  fillVector(vec1, vec2, max);
  // std::cout << "filled vecs" << std::endl;
  thread th1 = thread(checkPrimeVector, std::ref(vec1), std::ref(t1Count));
  thread th2 = thread(checkPrimeVector, std::ref(vec2), std::ref(t2Count));

  th1.join();
  th2.join();
  return (t1Count + t2Count);
}

int main(int argc, char *argv[]) {
  int topValue, option;
  if (argc != 3) {
    std::cout << "Usage:  primesMT maxToCheck mode" <<
    std::endl;
    exit(0);}
  try {
    topValue = std::stoi(argv[1]);
    option = std::stoi(argv[2]);
  } catch(std::exception& e) {
    std::cout << "Error: arguments must be integers" << std::endl;
    exit(0);
  }
  int returnedPrimeCount = 0;
  switch (option) {
    case 0: returnedPrimeCount = serialExecute(topValue);
      break;
    case 1: returnedPrimeCount = inefficientMultithread(topValue);
      break;
    default: returnedPrimeCount = efficientMultithread(topValue);
      break;}
  std::cout << "Found " << returnedPrimeCount
    << " prime numbers < " << topValue << std::endl;

  exit(0);
}
