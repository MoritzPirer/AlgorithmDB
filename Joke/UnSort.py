"""
With all these sorting algorithms has anyone ever asked the question?
'What if I don't even want to sort it? There is no algorithm for me!'
It is time to go against the trend and embrace unsortedness!

Time: O(Whatever the randomizer takes)
Space: O(1)

TAGS:
domain/joke
"""

import random


def isSorted(A: list[int]) -> bool:
    if len(A) <= 1:
        return True

    for i in range(1, len(A)):
        if A[i] < A[i - 1]:
            return False

    return True


def unsortArray(A: list[int]) -> list[int]:
    random.shuffle(A)

    while isSorted(A):
        random.shuffle(A)

    return A


def main():
    array = [int(i) for i in input("Enter the array (space seperated): ").split()]
    array = unsortArray(array)
    print("Your unsorted array is:", array)


if __name__ == "__main__":
    main()
