# logic:
# The point here is to find a formula that tests 
# if the number is a palindrome. The easy way to
# do this is to convert the number to string, slice
# it in half and reverse the second half.
# However this is a mathematical challenge, so it
# would be cheating.

def findDigits(n):
    digits = 0

    while n > 1:
        digits += 1
        n /= 10

    return digits


def isPalindrome(n, digits):
    for digit in range(digits // 2):

        right_digit = n % 10 ** (digit+1) // 10 ** digit
        left_digit = n  % 10 ** (digits-digit) // 10 ** (digits-digit-1)

        if left_digit != right_digit:
            return False

    return True


def euler4():
    max = 0
    
    for i in range(100, 1000):
        for y in range(100, 1000):
            n = i*y
            digits = findDigits(n)

            if isPalindrome(n, digits): 
                if n > max:
                    max = n

    return max


print(euler4())