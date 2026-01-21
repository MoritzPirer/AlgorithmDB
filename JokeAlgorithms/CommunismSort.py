"""
Are you tired of other array elements being larger than you?
Then rise up, bretheren! communismSort is a O(n) time and space algorithm
Where everyone gets treated equally
"""
def communismSort(A:list[int]) -> list[int]:
    average = sum(A) / len(A)
    
    return [average] * len(A)

def main():
    array = [int(i) for i in input("Enter the array (space seperated):\n> ").split()]
    print(communismSort(array))

main()