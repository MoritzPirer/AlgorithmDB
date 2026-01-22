import time

"""
Remember the incident in Belgium's 2003 federal election, where the electronic voting machines
registered 4096 extra votes for one candidate, caused by high-energy particles from space?
This error was like a miracle (for that one candidate), so it should also be able to sort
our array - you just have to wait long enough. Let it run, do something else and check on it later.
Is it sorted yet? No? Well, wait longer you impatient pickle.
"""


def isSorted(list):
    if len(list) == 0:
        print("Miracles cannot come from nothing.")
        exit(-1)

    prev_num = list[0]

    for num in list:
        if prev_num > num:
            return False

        prev_num = num

    return True


def main():
    A = input("Enter array (space seperated): ").split()
    A = [int(x) for x in A]

    while not isSorted(A):
        print("Any day now...")
        time.sleep(30)

    print("Sorted-Array:", A)
    return


if __name__ == "__main__":
    main()
