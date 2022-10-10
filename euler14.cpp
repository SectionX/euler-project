/* 
The Collatz sequence! This one is both fun and it gives
us a great opportunity to implement it recursively.
We will also do some memoization to optimize our solution

So, recursion. What is it? It's defining something by itself.
It's not a programming concept. It's a mathematical one.

Let's take a simple sequence of numbers, like 1,2,3,4,5.
We can view this sequence as incrementing the previous number
by one. 0+1, 0+1+1, 0+1+1+1 etc. This kind of algorithm is 
iterative.

We can also view it as a bunch of numbers that can be defined
by a single number of the sequence. For example
n-5, n-4, n-3, n-2, n-1, n. Since we transformed ever number
to have some relationship to n, we made the sequence recursive.

So how does this apply to Collatz? The next number of the sequence
has something to do with the current.

collatz(n) -> collatz(n/2) if even
              collatz(3n+1) if odd

Memoization:

This is the practice of logging the results so the algorithm can
retrieve them instead of calculating again.

For example, the collatz sequence for 5 is 
5 16 8 4 2 1

For 10, it's
10 5 16 8 4 2 1

As you can see, once the second sequence (collatz 10) reaches 5, it's the same
as the first sequence (collatz 5). So we already have our answer, no need to
keep calculating.

Implementing takes some used to. We will use an array to do it. The logic here
is to log every result in the array. So for arr[5] we will log 5. When
we try to calculate collatz(10), the moment n will reach 5, it will just retrieve
the result and add it to the previous step, for a total of 6. Then log arr[10] = 6

For this particular problem, the absolute difference isn't that amazing, but if you increase
the number of iterations to 10^7 or 10^8, then you will start noticing HUGE improvements.

Of course if you overdo it you will use all ram available, forcing the OS to use virtual
memory and freezing your computer.

 */
#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;

long ITERATIONS = 1000000;

struct numwithlog
{
    long num;
    long operations = 0;
};

numwithlog collatz(numwithlog &n, long *memo) {
    if (n.num < ITERATIONS && memo[n.num]) {
        n.operations += memo[n.num];
        return n;
    } 

    if (n.num <= 1) { 
        return n; 
    }

    if (n.num % 2 == 0) { 
        n.operations = n.operations + 1; 
        n.num = n.num / 2; 
        return collatz(n, memo);
    }

    if (n.num % 2 != 0) { 
        n.operations = n.operations + 1; 
        n.num = n.num * 3 + 1; 
        return collatz(n, memo);
    }

    return n;
}

long euler14(long iterations, long *memo) {
    long max = 0;
    long maxnum = 0;

    for (long i = 1; i < iterations; i++) {
        numwithlog n; 
        n.num = i;
        collatz(n, memo);
        memo[i] = n.operations;

        if (n.operations > max) {
            max = n.operations;
            maxnum = i;
        }
    }

    cout << max << endl;
    return maxnum;
}


int main() {
    auto start = chrono::high_resolution_clock::now();

    long *arr = new long[ITERATIONS]{0};

    cout <<  euler14(ITERATIONS, arr) << endl;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    cout << duration / pow(10,9)<< endl;

}