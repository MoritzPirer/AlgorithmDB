"""
calculates the n-th fibonacci number using a bottom up approach.
Time: O(n), Space: O(1)

Tags:
domain/math
paradigm/dynamic-programming
"""

def fibonacci(n:int) -> int:
    if (n == 0): return 0
    if (n <= 2): return 1 

    previous = 1
    current = 1
    for _ in range(3, n + 1):
        temp = previous + current
        previous = current
        current = temp

    return current

for i in range(10):
    print(f"{i}: {fibonacci(i)}")