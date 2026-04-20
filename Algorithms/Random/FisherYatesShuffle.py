"""
Generates a random permutation of an array with each permutation being equally likely
Time: O(n), Space: O(1)

TAGS:
domain/stat
prop/in-place
"""
import random

def fisherYatesShuffle(A:list[any]) -> None:
    for i in reversed(range(len(A))):
        j = random.randint(0, i)
        A[i], A[j] = A[j], A[i]

A = list(range(15))
fisherYatesShuffle(A)
print(A)