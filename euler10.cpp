// This is one of the problems where a basic understanding of
// how to optimize algorithms comes handy. With a very naive
// approach, it's quite hard to count so many primes.
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


unsigned long long euler10(unsigned long long n) {
  unsigned long long sum = 2 + 3 + 5;
  bool isPrime;
  unsigned long long cntr = 3;

  for (unsigned long long num = 7; num < n; num += 2) {
    isPrime = true;
    for (unsigned long long div = 3; div <= (unsigned long long) sqrt(num) + 1; div += 2) {
      if (num % div == 0) {
        isPrime = false;
        break;
      }
    } if (isPrime) { sum += num; cntr++;}
  }

  cout << cntr << endl;
  return sum;
}


int main () {
  cout << euler10(2000000) << endl;
}

