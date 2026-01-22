"""
You think BogoSort is too efficient and unprecise? BogoBogoSort solves this issue
by punishing sorting every prefix-subarray using BogoSort and punishing you
with a reset, should there be even a tiny mistake.
With O(n*(n!)^n) its runtime is so exorbitant high that even arrays with
little length are probably not done sorting by the heat-death of the universe!
Truly the ultimate sorting algorithm of all time and still faster than Miracle-Sort.
"""

import random


def isSorted(A: list[int]) -> bool:
    if len(A) <= 1:
        return True

    for i in range(1, len(A)):
        if A[i] < A[i - 1]:
            return False

    return True


def bogoSort(A: list[int]):
    random.shuffle(A)

    if isSorted(A):
        return A

    return None


def main():
    A = input("Enter array (space seperated): ").split()
    A = [int(x) for x in A]

    subA = []
    counter = 0

    while counter < len(A):
        subA.append(A[counter])

        subA = bogoSort(subA)

        if subA is None:  # It's like the gambling meme - Ah dangit!
            subA = []
            counter = 0
        else:
            counter += 1

    print("Sorted-Array:", subA)
    return


if __name__ == "__main__":
    main()
