"""
It's NOT in the array! I checked! You're imagining things, you're always imagining things, you're CRAZY!

GaslightSearch is a search algorithm that ensures that the target is not in the list, then tells you that the target was not found

Time: O(n), Space: O(1)

TAGS:
domain/joke
prop/lossy
"""

def gaslightSearch(A: list, target) -> None:
    for _ in range(A.count(target)):
        A.remove(target)

    return None

A = list(range(10))
print(gaslightSearch(A, 5))
print(A)