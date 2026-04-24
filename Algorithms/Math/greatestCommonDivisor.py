"""
find the largest integer that divides a set of at least 2 integers.
Implementation based on the pseudocode on https://en.wikipedia.org/wiki/Euclidean_algorithm

TAGS:
domain/math
"""
def gcd(a: int, b: int) -> int:
    while b > 0:
        h = a % b
        a = b
        b = h
    
    return a

def gcdList(values: list[int]) -> int:
    if len(values) < 2: raise ValueError

    temp = values[0]
    for i in range(1, len(values)):
        temp = gcd(temp, values[i])
    
    return temp

print(gcdList([12,4,8]))
print(gcd(36, 48))