"""
BubbleSort is a simple but inefficient comparison-based sorting algorithm that works 
by comparing neighboring elements and swapping them if they aren't in the correct order

Time: O(n^2), Space: O(1)

Tags:
domain/sort
prop/stable
prop/in-place
"""

def bubbleSort(A:list) -> None:
	made_change = True
	while made_change:
		made_change = False
		for i in range(0, len(A) - 1):
			if (A[i] > A[i + 1]):
				A[i], A[i + 1] = A[i + 1], A[i]
				made_change = True

A = [10, 8, 1, 4, 11, 14, 9, 5, 12, 6, 7, 0, 3, 2, 13]
bubbleSort(A)
print(A)