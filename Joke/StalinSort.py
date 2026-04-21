"""
If you don't fit Stal-IN, time to get stal-OUT!
StalinSort is a linear time lossy sorting algorithm that trades data loss for runtime.
The amount of data lost depends on the initial input

Time: O(n), Space: O(n), Stable
TAGS:
domain/joke
prop/stable
prop/lossy
"""

def stalinSort(A:list[int]) -> list[int]:
    if len(A) == 0:
        return A
    current_max = A[0]
    B = []

    for element in A:
        if element > current_max:
            current_max = element
            B.append(element)
    
    return B

def main():
    array = [int(i) for i in input("Enter the array (space seperated):\n> ").split()]
    print(stalinSort(array))

main()