/* 
2D arrays require discipline. It's easy to mess them up and spend a lot
of time debugging. Additionally, dealing dynamically with going out of 
bounds is complicated. The easiest way for this exercise is to just extend
the arrays with an identity number, like 1 for multiplication, or 0 for 
addition. 

A second idea would be to multiply by identity every time the cursor
goes out of bounds. The problem is that having multiple cursors overcomplicates
the problem.

The last idea would be to do exception handling. I'm not sure how it works in
C++ but I have tried this approach in Python in the past. It's really messy and 
hard to read/debug though.
*/


#include <iostream>
#include <vector>

using namespace std;

string INPUT =
"08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 "
"49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 "
"81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 "
"52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 "
"22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 "
"24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 "
"32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 "
"67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 "
"24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 "
"21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 "
"78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 "
"16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 "
"86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 "
"19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 "
"04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 "
"88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 "
"04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 "
"20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 "
"20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 "
"01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48 "
;

string SPACE = " ";
string NL = "\n";

void vectorfrominput(vector<vector<long>> &arr2d, string stream, size_t len = 0, long pbnum = 1) {
  long num;
  while (stream.find(SPACE) != string::npos) {
    vector<long> arr1;
    for (long i = 0; i < 20; i++) {
    num = stoi(stream.substr(0, stream.find(SPACE)));
    stream = stream.substr(stream.find(SPACE) + 1);
    arr1.push_back(num);
    
    }
    for (long i = 0; i < len; i++) {
      arr1.push_back(pbnum);
    }
    arr2d.push_back(arr1);
  }
  for (long i = 0; i < len; i++) {
    arr2d.push_back(vector<long> {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1});
  }


  return;
}

long euler11(vector<vector<long>> arr2d, size_t len) {
  long prodrow, prodcol, proddiag, proddiagrev, maxprod = 1;


  for (size_t row = 0; row < 20; row++) {
    for (size_t col = 0; col < 20; col++) {
      prodrow = 1; prodcol = 1; proddiag = 1; proddiagrev = 1;
      for (size_t cur = 0; cur < len; cur++) {
          prodrow *= arr2d[row][col+cur];
          prodcol *= arr2d[row+cur][col];
          proddiag *= arr2d[row+cur][col+cur]; 
          proddiagrev *= arr2d[row+cur][col+len-1-cur];
      }
      for (long x: vector<long> { prodrow, prodcol, proddiag, proddiagrev })
        if (x > maxprod) {
          maxprod = x;
        }
    }
  }


  return maxprod;
}


int main() {
  size_t len = 4;
  vector<vector<long>> arr2d;
  vectorfrominput(arr2d, INPUT, len);
  cout << euler11(arr2d, len) << endl;
  return 0;
}
