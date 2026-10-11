"""
'Money is the anthem of success and the reason we exist'
With the rise of Communism-Sort, an alternative for all hard-working, honest, freedom-loving
people is needed!
Capitalism Sort "sorts" people in their place, by simulating realistic and fair redistribution
of value towards the hardest-working people.
Really, everyone can make it big here, only have to put in some work and you're rewarded.

Time: O(n * rounds the fair market needs)
Space: O(1)

TAGS:
domain/joke
"""

def capitalismSort(A:list[float]) -> list[float]:
  # Identify the richest (most important) person
  richest_indx = A.index(max(A))

  while True:

    # There is no more money to get :(
    if A.count(0.0) == (len(A) - 1):
      return [int(i) for i in A]

    earnings = 0.0
    for i in range(len(A)):
      if i is richest_indx:
        continue

      # Eat the poor *Cough* I mean... bankrupt them...
      if A[i] <= 0.5:
        earnings = earnings + A[i]
        A[i] = 0
      # Everyone remotely monetary stable owes the richest 10% of their wealth
      else:
        debt = A[i] * 0.1
        earnings = earnings + debt
        A[i] = A[i] - debt

    # Enlarge richest' ones wealth
    A[richest_indx] = A[richest_indx] + earnings


def main():
    array = [float(i) for i in input("Enter the array (space seperated): ").split()]
    array = capitalismSort(array)
    print("Your (technically) sorted array is:", array)


if __name__ == "__main__":
    main()
