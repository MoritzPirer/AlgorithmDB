"""
I don't want to rely on this corporate modulo, I am writing my own standard-functions!

Time: O(1), Space: O(1)

TAGS:
domain/joke
"""


def isEven(num):
    return isEvenInternal(num, True)


def isOddInternal(num, same_bool):
    return not isEvenInternal(num, same_bool)


def isEvenInternal(num, same_bool):
    if num == 0:
        return same_bool

    return not isOddInternal(num - 1, not same_bool)


def main():
    num = int(input("Enter your number: "))

    result = isEven(num)

    print("Is the number even?", result)

    return


if __name__ == "__main__":
    main()
