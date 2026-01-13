class QuickSort:
  def sort(self, A:list):
    self.step = 1
    self.quickSort(A, 0, len(A) - 1)

  def show(self, A:list):
    print(str(self.step) + ". partition:")
    self.step += 1
    print(" ".join(map(str, A)))
    print("\n", "-" * 30)

  def quickSort(self, A:list, low:int, high:int):
    if low < high:
      (A, pivot_index) = self.partition(A, low, high)
      self.quickSort(A, low, pivot_index - 1)
      self.quickSort(A, pivot_index, high) 
  
  def partition(self, A:list, low:int, high:int):
    pivot = A[high]
    i, j = low - 1, high + 1
    while i < j:
      i += 1
      while A[i] < pivot:
        i += 1
      j -= 1
      while A[j] > pivot:
        j -= 1
      if i < j:
        (A[i], A[j]) = (A[j], A[i])
    self.show(A)
    return A, i

def main():
    A = input("Enter array (space seperated): ").split()
    A = [int(x) for x in A]
    QuickSort.sort(A)