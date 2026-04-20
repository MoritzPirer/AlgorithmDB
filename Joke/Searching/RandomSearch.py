"""
[street magician voice] is THIS your index? ... it isn't? shoot, lemme try again

As opposed to binary Search, where the best case only occurs if the target is in the middle of the array,
randomSearch has the chance to find the target instantly regardless of where it is.

Time: O(n), Space: O(n)

TAGS:
domain/joke
"""

import random

def randomSearch(A: list[any], target: any) -> int | None:
    unseen = list(range(len(A)))
    while len(unseen) > 0:
        guess_index = unseen[random.randint(0, len(unseen) - 1)]

        if A[guess_index] == target:
            return guess_index

        unseen.pop(guess_index)

print(randomSearch(list(range(52)), 13))