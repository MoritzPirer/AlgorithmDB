"""
If your Array disappears, technically it's sorted. At least its not not sorted I guess?
"""

# O(1) time and space lossy array sorting
def hiroshimaSort(A:list[int]) -> list[int]:
    return [] #boom. sorted

def main():
    array = [int(i) for i in input("Enter the array (space seperated):\n> ").split()]
    print(hiroshimaSort(array))

main()