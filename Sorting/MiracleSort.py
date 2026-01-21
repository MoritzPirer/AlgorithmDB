import time


def isSorted(list):
    if len(list) == 0:
        print("Miracles cannot come from nothing.")
        exit(-1)

    prev_num = 0
    for num in list:
        if prev_num >= num:
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
