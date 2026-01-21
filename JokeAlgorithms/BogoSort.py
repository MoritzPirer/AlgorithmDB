"""
If you want to break free of the shackles of the 'efficient algorithm' hoax
bogoSort is the perfect algorithm for your use case. With it's elegant O(n!) runtime,
it challenges conventional wisdom in a breathtaking way.
"""
import random

def isSorted(A:list[int]) -> bool:
    if len(A) <= 1: return True

    for i in range(1, len(A)):
        if A[i] < A[i - 1]:
            return False
    
    return True

def bogoSort(A:list[int]):
    while True:
        if isSorted(A):
            return
        random.shuffle(A)

def main():
    array = [int(i) for i in input("Enter the array (space seperated):\n> ").split()]
    bogoSort(array) 
    print(array)

main()