"""
Constant means everything takes the same amount of time, not that it's very little time.
Just use a very large constant????

Time: O(1) (As long as the constant is large enough) Space: O(n log n)

TAGS:
domain/joke
"""

import time
import random

def roundUpSort(A:list[int]) -> None:
    start = time.time()
    A.sort()
    end = time.time()

    if duration > 10:
        print("[ERROR] Invalid Input: please use a shorter array to ensure constant time sorting")
    duration = end - start
    time.sleep(10-duration)

A = list(range(1_000_000))
random.shuffle(A)
roundUpSort(A)
print("A done")    
A = list(range(100))
random.shuffle(A)
roundUpSort(A)
print("B done")    