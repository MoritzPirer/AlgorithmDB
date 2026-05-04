"""
exponentiation by squaring is a faster method to calculate x^n where n is an integer.
it works by repeatedly squaring x, which reduces the number of calculations needed

NOTE: this algorithm should not be used for encryption (e.g. RSA),
as the exponent used can potentially be recovered by an attacker

Time: if two d-digint numbers can be multiplied in O(d^k) for a fixed k: O((n log x)^k)
Space: O(1)

TAGS:
domain/math
"""

def exponentiationBySquaring(x: float, n: int) -> float:
    if n == 0:
        return 1
    if n < 0:
        return exponentiationBySquaring(1 / x, -n)
    
    y = 1
    while n > 1:
        if n % 2 == 1:
            y *= x
            n -= 1
        x *= x
        n /= 2
    
    return x * y

def p(x,n):
    return exponentiationBySquaring(x,n)
