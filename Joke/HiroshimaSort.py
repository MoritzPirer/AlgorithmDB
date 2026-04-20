"""
If your Array disappears, technically it's sorted. At least its not not sorted I guess?
HiroshimaSort is a constant-time hyper-lossy sorting algorithm that avoids the O(n log n) lower bound
for comparison-based sorting by ensuring that there are no elements to compare.

Time: O(1), Space: O(1)

TAGS:
domain/joke
prop/lossy
"""

# O(1) time and space lossy array sorting
def hiroshimaSort(A:list[int]) -> list[int]:
    return [] #boom. sorted

def main():
    array = [int(i) for i in input("Enter the array (space seperated):\n> ").split()]
    print(hiroshimaSort(array))

main()