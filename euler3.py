def eulerID3(n):

    nroot = int(n ** 0.5)
    max = 2
    primes = [2, 3]
    for num in range(5, nroot+1, 2):
        isPrime = True
        for div in range(3, int(num**0.5)+1, 2):
            if num % div == 0:
                isPrime = False
                break
        if isPrime: primes.append(num)

    for prime in primes:
        if n % prime == 0:
            max = prime

    return max

print(eulerID3(600851475143))