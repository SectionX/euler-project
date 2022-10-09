// This is one of the times that I really don't want to use
// any other language than Python. I don't think there is a
// language that processes strings better than it.

// For example, converting a char to integer took me a lot
// of time to debug.

// Lastly, I used long type, which wasn't enough to contain the
// result, and I couldn't get feedback on why the result was wrong.

// In any case, it's completely pointless to treat the number
// as a number type. Will find a way to iterate through the
// numbers, thirtheen at a time, and return the highest product.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string STR =

"73167176531330624919225119674426574742355349194934"
"96983520312774506326239578318016984801869478851843"
"85861560789112949495459501737958331952853208805511"
"12540698747158523863050715693290963295227443043557"
"66896648950445244523161731856403098711121722383113"
"62229893423380308135336276614282806444486645238749"
"30358907296290491560440772390713810515859307960866"
"70172427121883998797908792274921901699720888093776"
"65727333001053367881220235421809751254540594752243"
"52584907711670556013604839586446706324415722155397"
"53697817977846174064955149290862569321978468622482"
"83972241375657056057490261407972968652414535100474"
"82166370484403199890008895243450658541227588666881"
"16427171479924442928230863465674813919123162824586"
"17866458359124566529476545682848912883142607690042"
"24219022671055626321111109370544217506941658960408"
"07198403850962455444362981230987879927244284909188"
"84580156166097919133875499200524063689912560717606"
"05886116467109405077541002256983155200055935729725"
"71636269561882670428252483600823257530420752963450"

;


long long euler8(string &str, int len) {
  long long prod = 1;
  long long maxprod = 1;
  char *tmp = new char(len+1);
  char *max = new char(len+1);

  for (long long cursor = 0; cursor < str.length() - (len-1); cursor++) {
    prod = 1;

    for (long long i = cursor; i < cursor + len; i++) {
      prod = prod * ((long long) str[i] - (long long) '0');
      tmp[i-cursor] = str[i];
    }
    if (prod > maxprod) {
      maxprod = prod;
      for (int i = 0; i < len; i++) {
        max[i] = tmp[i];
     }
    }
  }

  for (int i = 0; i < len; i++) {
    cout << max[i];
  } cout << endl;
  return maxprod;
}




int main() {
  cout << euler8(STR, 13) << endl;
  // long long num = 23514624000;
  // cout << num << endl;
}
