"""
RULES:

- Given an array of integers, find the subarray with the largest sum
    (and/or the start end of that subarray)
"""

def subarraySum(A):
    n = len(A)

    if n == 0:
        return 0

    S = [0] * n

    for k in range(n):
        S[k] = max(0, S[k - 1] + A[k])

    return max(S)

def indexOf(A, value):
    a = []
    for i, element in enumerate(A):
        if element == value:
            a.append(i)
    return a

def subarraySumIndecies(A):
    n = len(A)

    #empty array
    if n == 0:
        return (None, None)
    
    S = [0] * n
    Starts = [0] * n

    for k in range(n):
        S[k] = max(0, S[k - 1] + A[k])
        if k > 0:
            if S[k - 1] + A[k] > 0:
                Starts[k] = Starts[k - 1]
            else:
                Starts[k] = k
                
    max_sum = max(S)

    #all elements were negative, best to take nothing
    if (max_sum == 0):
        return (None, None)
    
    i = min(indexOf(S, max_sum))

    #cover edge cases for short arrays
    start = 0
    if (i > 0):
        zero_indecies = indexOf(S[0:1], 0)
        if len(zero_indecies) != 0:
            start = max(zero_indecies) + 1;
    
    return (start, i)

def main():
    array = [int(i) for i in input("Enter the array (space seperated):\n> ").split()]
    selection = int(input("enter 1 if you want the sum or 2 if you want the start/end indecies of the best subarray:\n> "))
    if (selection == 1):
        print(subarraySum(array))
    elif (selection == 2):
        print(subarraySumIndecies(array))
    else:
        print("Invalid selection. Fuck you. Crashing now...")
        print(1/0)


main()