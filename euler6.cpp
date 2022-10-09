// Instead of looping, we can use the formulas for series sums
// for Σn it's n/2 * (n+1)
// for Σn^2 it's (2n^3 + 3n^2 + n) / 6

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long euler6(long n) {
  vector<long> nums;

  for (int i = 1; i <= n; i++) {
    nums.push_back(i);
  }

  long sumofsquares = (2 * pow(n, 3) + 3 * pow(n, 2) + n) / 6;

  long squareofsums = pow(n/2 * (n+1), 2);

  return squareofsums - sumofsquares;
}



int main() {
  cout << euler6(10) << endl;
  cout << euler6(100) << endl;
}
