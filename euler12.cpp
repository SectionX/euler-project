/*
When working with divisors, it's important to consider
the square root of a number.
For example: 

We have the number 100. It's sqrt is 10.
For numbers up to 10, the combinations are
1 x 100
2 x 50
4 x 25
5 x 20
10 x 10

From there on, the rest of the combinations
will be the reverse.

20 x 5
25 x 4
50 x 2
100 x 1

Take another example, 28: It's sqrt is 5
1 x 28
2 * 14
4 * 7

7 * 4
14 * 2
28 * 1

So the number with most divisors up to it's
root, is the number with the most divisors in
general. Any number who's root has less divisors
than the previous max will be discarded.

One thing to note here, is that numbers with
perfect roots, have one extra divisor.

Lastly, the exercise doesn't take the number itself
as it's divisor, so we have to subtract it. Also
the algorithm struggles for numbers less than 10 but
we don't need a computer to calculate those so I 
won't try to fix it.

*/

#include <iostream>
#include <cmath>
using namespace std;

long euler11(long condition) {
    long num = 0;
    long max_digit_divs = 0;
    long no_of_divs = 0;
    long index = 0;
    while (no_of_divs < condition) {
        no_of_divs = 0;
        index++;
        num += index; 
        for (long i = 1; i < (long) sqrt((double) num); i++) {
            if (num % i == 0) 
                no_of_divs++;
        }
        no_of_divs *= 2;
        if (max_digit_divs < no_of_divs) {
            max_digit_divs = no_of_divs;
        }
        if (fmod(sqrt((double) num), 1) == 0) {
            no_of_divs++;
        }

        if (no_of_divs >= max_digit_divs) {
            no_of_divs--;
            cout << num << " - " << no_of_divs << " - " << max_digit_divs << endl;
        }

    }
    
    return num;
}

int main() {

    cout << euler11(1000) << endl;



    return 0;
}