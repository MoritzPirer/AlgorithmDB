"""
If you don't fit Stal-IN, time to get stal-OUT
"""

# O(n) lossy sorting
def stalinSort(A:list[int]) -> list[int]:
    if len(A) == 0:
        return A
    current_max = A[0]
    B = []

    for element in A:
        if element >= current_max:
            current_max = element
            B.append(element)
    
    return B

def main():
    array = [int(i) for i in input("Enter the array (space seperated):\n> ").split()]
    print(stalinSort(array))

main()