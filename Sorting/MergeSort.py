"""
MergeSort works by splitting the list in half repeatedly and re-assembling it in a sorted way
"""
class MergeSort:
    def sort(self, A: list):
        self.step = 1
        self.mergeSort(A, 0, len(A) - 1)
        self.show()

    def show(self, A: list):
        print(f"{self.step}. merge:")
        self.step += 1
        print(" ".join(map(str, A)))
        print("\n" + "-" * 30)

    def mergeSort(self, A: list, left: int, right: int):
        if left < right:
            mid = (left + right) // 2
            self.mergeSort(A, left, mid)
            self.mergeSort(A, mid + 1, right)
            self.merge(A, left, mid, right)

    def merge(self, A: list, left: int, mid: int, right: int):
        L = A[left:mid + 1]       
        R = A[mid + 1:right + 1]  
        i = j = 0
        k = left
        while i < len(L) and j < len(R):
            if L[i] <= R[j]:
                A[k] = L[i]
                i += 1
            else:
                A[k] = R[j]
                j += 1
            k += 1
        while i < len(L):
            A[k] = L[i]
            i += 1
            k += 1
        while j < len(R):
            A[k] = R[j]
            j += 1
            k += 1
 
def main():
    A = input("Enter array (space seperated): ").split()
    A = [int(x) for x in A]
    MergeSort().sort(A)

main()