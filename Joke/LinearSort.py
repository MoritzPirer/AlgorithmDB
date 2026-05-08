import sys
import time

sys.path.insert(1, "Algorithms/Sorting")

import MergeSort

"""
Computer Scientists all over the world baffeled about the first ever linear sorting-algorithm!
The math in all cases checks out and it scales linearly with the input :P
(You got a couple of days to wait for the result, right?)
Reference: https://xkcd.com/3026/

Time: O(n) - Best case, Worst case is that someone checks why
Space: O(1)

TAGS:
domain/joke
"""


def linearSort(A):
    start_time = time.time()
    MergeSort.MergeSort().sort(A)
    time.sleep(1e6 * len(A) - (time.time() - start_time))
    return A


def main():
    A = input("Enter array (space seperated): ").split()
    A = [int(x) for x in A]

    sorted_array = linearSort(A)

    print("Sorted-Array:", sorted_array)
    return


if __name__ == "__main__":
    main()
