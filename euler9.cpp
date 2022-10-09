// This is an interesting one.

// It's fairly easy to bruteforce it with 2 loops
// And since the exercise is supposed to be easy
// I'll leave it at that. However there are some interesting
// concepts that we can use with power subtraction to
// approach a more complex problem. For example,
// (n)^2 - (n-1)^2 gives all odd numbers.
// (n)^2 - (n-2)^2 gives all multiples of 4

#include <iostream>
#include <cmath>

using namespace std;

long euler9() {
  for (long a = 1; a < 500; a++ ) {
    for (long b = 1; b < 500; b++) {
      double c = sqrt(pow(a,2) + pow(b, 2));
      if (fmod(c, 1) == 0) {
        cout << a << ',' << b << ',' << c << endl;
      }
      if (a + b + c == 1000) {
        cout << a << ',' << b << ',' << c << endl;
        cout << a * b * (long) c;
        return 0;
      }
    }
  } return 0;
}

int main() {
  euler9();
}
