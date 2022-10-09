# 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
# What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

# Logic:
# The naive approach takes quite a while to compute the result
# A less naive approach is to consider that all numbers are either
# primes or a combination of primes. This will narrow down the 
# search significantly.

from time import perf_counter


def calcPrimes(n):
    primes = [2,3,5]

    for i in range(7, n+1, 2):
        isPrime = True

        for y in range(3, int(i**0.5)+1, 2):
            if i % y == 0:
                isPrime = False
                break

        if isPrime:
            primes.append(i)
        
    return primes
        


def euler5(n):
    divs = list(range(1,n+1))
    print(divs)
    i = 1

    while True:
        y = 0

        for div in divs:
            if i % div == 0:
                y += 1

        if y == len(divs):
            return i

        i += 1
        # print(i)

start = perf_counter()
print(euler5(18))
print(perf_counter() - start)
# calcPrimes(100)
