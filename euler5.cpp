// Since these are mostly math operations, I switched to C++ for the extra speed,
// and I could use the practice to get familiar with the language. I may switch
// to something else later.

// This is a naive solution that took a lot of processing power. I can't think
// of a better one though.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


long euler5(long n) {
  vector<long> divs;
  long num = 1;
  long cntr;

  for (long i = 1; i <= n; i++) {
    divs.push_back(i);
  }

  while (1) {
    cntr = 0;

    for (long div: divs) {
      if (num % div != 0) {
        break;
      } cntr++;

      if (n == cntr) {
        return num;
      }
    }

    num++;

  }

  return divs[n-1];

}

int main() {
    cout << euler5(20) << endl;
}
