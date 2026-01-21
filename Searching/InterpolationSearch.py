"""
InterpolationSearch works similar to binary search, but instead of splitting the
search space in half, it estimates the position of the target based on the values at 
the ends of the range. Works well for data that is approximately linearly distributed
"""
import math

def interpolationSearch(array: list[int], target: int) -> int:
    left = 0
    right = len(array) - 1

    while (left <= right and array[left] <= target <= array[right]):
        if (left == right):
            return left if array[left] == target else None;
        
        # Estimate position
        position = left + math.floor(
            ((target - array[left]) * (right - left)) /
            ((array[right] - array[left]))
        )

        if (array[position] == target):
            return position
        elif (array[position] < target):
            left = position + 1
        else:
            right = position - 1

def main():
    A = input("Enter array (space seperated): ").split()
    A = [int(x) for x in A]
    t = int(input("Enter the target value: "))
    print(f"Target is at index {interpolationSearch(A, t)}")

main()