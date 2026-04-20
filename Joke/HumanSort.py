"""
Any good developer knows that the computer is acutally their enemy, and they want less computer in their life.
So when it comes to sorting, put your trust in the ones that tricked a rock into thinking, not the rock that was tricked.

Note that this is a *probabilistic* algorithm as lack human error cannot be guaranteed.

Time: O(user_speed), Space: O(n)

TAGS:
domain/joke
prop/probabilistic
"""

def humanSort(A:list[int]) -> list[int]:
    B = []
    for _ in range(len(A)):
        print(f"What's the minimum in this list: {A}?")
        try:
            min_value = int(input("> "))
            index = A.index(min_value)
            A.pop(index)
            B.append(min_value)
        except ValueError:
            print("You lied to me :(((")
            B.append(A[-1])
            A.pop()

    print("Boy I sure hope you didn't make a mistake")
    return B


print(humanSort([1, 23, 246, 4567, 245, 12, 3]))
