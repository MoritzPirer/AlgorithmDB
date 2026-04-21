"""
To restore balance in the world, half of it needs to disappear. Or whatever.
ThanosSort is a non-deterministic lossy sorting algorithm that reduces the problem set until a solution is found

Time: ~O(n log n), Space: O(1)
"""

import random

def isSorted(A:list[int]) -> bool:
    if len(A) <= 1: return True

    for i in range(1, len(A)):
        if A[i] < A[i - 1]:
            return False
    
    return True

def snap(A:list[int]) -> None:
    for _ in range(len(A) // 2):
        i = random.randint(0, len(A) - 1)
        A.pop(i)

def thanosSort(A:list[int]) -> list[int]:
    while not isSorted(A):
        snap(A)

    return A

def main():
    array = [int(i) for i in input("Enter the array (space seperated):\n> ").split()]
    print(thanosSort(array))

main()