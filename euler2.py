def eulerID2():
    fib = [0,1]
    sum = 0

    while fib[-1] < 4_000_000:
        fib.append(fib[-2]+fib[-1])
    fib.pop()

    for n in fib:
        if n % 2 == 0:
            sum += n

    return sum

print(eulerID2())