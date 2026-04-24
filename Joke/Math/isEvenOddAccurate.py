"""
Many use LLMs or mail-service to query an african child to find out whether a number is odd.
This advanced algorithm does it on your machine, so you needn't worry about that anymore!
Although it only goes up to 30, it should serve as an example, which is quite easily extendable for each use-case!

Time: O(1), Space: O(1)

TAGS:
domain/joke
"""


def isOdd(num):
    if num == 1:
        return True
    elif num == 2:
        return False
    elif num == 3:
        return True
    elif num == 4:
        return False
    elif num == 5:
        return True
    elif num == 6:
        return False
    elif num == 7:
        return True
    elif num == 8:
        return False
    elif num == 9:
        return True
    elif num == 10:
        return False
    elif num == 11:
        return True
    elif num == 12:
        return False
    elif num == 13:
        return True
    elif num == 14:
        return False
    elif num == 15:
        return True
    elif num == 16:
        return False
    elif num == 17:
        return True
    elif num == 18:
        return False
    elif num == 19:
        return True
    elif num == 20:
        return False
    elif num == 21:
        return True
    elif num == 22:
        return False
    elif num == 23:
        return True
    elif num == 24:
        return False
    elif num == 25:
        return True
    elif num == 26:
        return False
    elif num == 27:
        return True
    elif num == 28:
        return False
    elif num == 29:
        return True
    elif num == 30:
        return False

    return None


def main():
    num = int(input("Enter your number (please only up to 30): "))

    result = isOdd(num)

    if result is None:
        print("Is the number odd? Can't tell")
    else:
        print("Is the number odd?", result)

    return


if __name__ == "__main__":
    main()
