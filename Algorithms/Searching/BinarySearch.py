"""
Binary Search is an efficient search algorithm that works on sorted data. Duplicate items are allowed,
but no guarantees can be made about which instance is found (as opposed to, e.g. linear search).

Binary Search can be applied in any scenario where data is sorted in some way (e.g. number ranges) and where
inspecting an item that is not the target can give a higher / lower answer to reduce the search space

Time: O(log(n)), Space: O(1)

TAGS:
domain/search
paradigm/binary-search
"""
def binarySearch(A: list[any], target: any) -> int | None:
    if (len(A) == 0): return None

    left = 0
    right = len(A) - 1

    while left <= right:
        # calculating mid like this prevents overflow
        mid = left + (right - left) // 2 
        if A[mid] == target:
            return mid
        elif A[mid] < target:
            left = mid + 1
        elif A[mid] > target:
            right = mid - 1
    
    return None

print(binarySearch([1, 2, 3, 4, 5, 6, 7, 8, 9], 2))