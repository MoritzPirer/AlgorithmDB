"""
RULES:
- You have a list of n items with a weight and value
- You have a knapsack with a maximum weight it can hold
- You want to find the maximum value you can fit in the knapsack without going over the
    weight, and what items to take for that value
"""

def generateKnapsackTable(weights: list[int], values: list[int], capacity: int) -> list[list[int]]:
    n = len(weights)
    table: list[list[int]] = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]

    for i in range(1, n + 1):  # i = 1 to n
        for w in range(0, capacity + 1):  # w = 0 to capacity
            if weights[i - 1] <= w:
                # Max of: not taking the item, or taking it
                table[i][w] = max(
                    table[i - 1][w],  # Don't take item i
                    table[i - 1][w - weights[i - 1]] + values[i - 1]  # Take item i
                )
            else:
                table[i][w] = table[i - 1][w]  # Can't take item i

    return table

def printFormatted(table:list[list[int]]) -> None:
    max_value = max(max(row) for row in table)
    cell_width = len(str(max_value))

    # Print header
    print("     ", end="")
    for capacity in range(len(table[0])):
        print(str(capacity).rjust(cell_width), end=" ")
    print()
    print("--" * cell_width * len(table[0]))
    # Print rows
    for i, row in enumerate(table):
        print(f"i={i}".ljust(5), end="")
        for val in row:
            print(str(val).rjust(cell_width), end=" ")
        print()

def generateZeroOneList(table:list[list[int]], weights:list[int], values:list[int], capacity:int) -> int:
  row = len(table) - 1
  column = capacity
  taken = [0] * row

  while row > 0 and column >= 0:
      if table[row][column] != table[row - 1][column]:
          taken[row - 1] = 1
          column -= weights[row - 1]
      row -= 1
  
  return taken

def getTakenItemList(taken:list[int]):
   return [i + 1 for i, x in enumerate(taken) if x == 1] 

def knapsack():
    weights = list(map(int, input("Enter the weights space-seperated: ").split()))
    values = list(map(int, input("Enter values space-seperated: ").split()))
    capacity = int(input("Enter capacity: "))

    result = generateKnapsackTable(weights, values, capacity)
    printFormatted(result)

    print("Take items:")
    print(" ".join(list(map(str,getTakenItemList(generateZeroOneList(result, weights, values, capacity))))))

knapsack()
