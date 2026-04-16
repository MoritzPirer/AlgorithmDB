import random

"""
Magicians always show you a card and ask you "Is this your card?"
This algorithm uses the same principle: audience participation.
People love being part of the trick, so might as well let them sort the array -
this yields a guaranteed satisfiable result, at least for the person sorting here.
"""


def badStreetMagician(A):
    sorted_array = []

    print(
        "I am gonna show you a number - tell me if it is the next number in the sorted list"
    )

    while A:
        chosen_num = random.choice(A)
        print("Is this the next number? ->", chosen_num, "\n[Y/N]")
        answer = input()

        if answer == "Y" or answer == "y":
            sorted_array.append(chosen_num)
            A.remove(chosen_num)
            print("Of course I knew that, I'm a magician after all!\n")
        else:
            print("Damnit, let me try again.\n")

    return sorted_array


def main():
    A = input("Enter array (space seperated): ").split()
    A = [int(x) for x in A]

    sorted_array = badStreetMagician(A)

    print("Sorted-Array:", sorted_array)
    return


if __name__ == "__main__":
    main()
