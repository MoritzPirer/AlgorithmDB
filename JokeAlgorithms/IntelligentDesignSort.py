"""
For a list of 10 values, there are more than 3.6 million ways to arrange them.
The chance of your data being in the order it is in is 0,000028%. Clearly, a higher
power wanted the data to be in *exactly* this order. Therefore, your list is already
sorted (you just could never understand by what metric)
O(1) time and space
"""

def intelligentDesignSort(A:list[int]):
    print("I dunno man, looks sorted to me...")
    return A

def main():
    array = [int(i) for i in input("Enter the array (space seperated):\n> ").split()]
    print(intelligentDesignSort(array))
    
main()