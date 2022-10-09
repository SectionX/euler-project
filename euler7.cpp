// There are a lot of ways to calculate primes. For this
// exercise I will use an optimized procedural approach
// but there are others like Eratosthenes sieve. If another
// problem asks for bigger prime numbers, I may use it.

// There are three important optimizations in this calculation
// First is iterating up to the sqrt of the tested number. This
// Second is to break the loop if a number fails the test.
// Third is to iterate 2 steps at a time and only odd numbers.
// Even numbers other than 2 can't be primes. To do the last one
// we need to provide a headstart.

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


long euler7(long n) {
  vector<long> primes = vector<long>{2,3,5};
  long i = 7;
  bool isPrime;
  while (primes.size() < n) {
    isPrime = true;
    for (long y = 3; y <= (long) sqrt(i) + 1; y += 2) {
      if (i % y == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      primes.push_back(i);
    }
    i += 2;
  }

  return primes[primes.size()-1];



  return 0;
}



int main() {
  cout << euler7(10001) << endl;
  cout << euler7(1000001) << endl;
}
