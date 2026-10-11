"""
Efficient linear sorting is possible! Through weird quantum-shenanigans!
Based on the many-worlds interpretation of quantum mechanics, Quantum Bogo-Sort operates under the assumption that
for any random event, all possible outcomes occur in separate, newly created universes. This algorithm therefore simulates
a quantum entropy-source and generates a random permutation of the given array.
If the array is sorted, the algorithm succeeds, otherwise it triggers the destruction of the universe
(we don't need these imperfect, obsolete results!).

This means, from a surviving universe's observers' perspective, the array is sorted in one run very efficiently!
(Although by executing this you probably committed mass-gen***de... At least the array was worth it)

Time: O(n)
Space: O(1)

TAGS:
domain/joke
"""

import sys
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
# Install the packages through pip

def isSorted(A:list[int]) -> bool:
    if len(A) <= 1: return True

    for i in range(1, len(A)):
        if A[i] < A[i - 1]:
            return False

    return True

def quantumEntropySource(start:int, end:int) -> int:
  span = end - start + 1
  num_qubits = (span - 1).bit_length()

  while True:
      qc = QuantumCircuit(num_qubits, num_qubits)
      qc.h(range(num_qubits))
      qc.measure(range(num_qubits), range(num_qubits)) # Oh no, the superposition collapsed!

      # Actual simulation of quantum-computer
      sim = AerSimulator()
      result = sim.run(qc, shots=1).result()
      binary = list(result.get_counts(qc).keys())[0]

      # Binary to integer + check
      val = int(binary, 2)
      if val < span:
          return start + val


def destroyUniverse():
  print("ERROR: Universe terminated.")
  # TODO: Run garbage-collector (False Vacuum Decay), then delete current universe
  sys.exit(1)


def quantumBogoSort(A:list[int]):
  for i in range(len(A), 1, -1):
    # Quantum Fisher-Yates Shuffle
    j:int = quantumEntropySource(0, i - 1)
    [A[i], A[j]] = [A[j], A[i]]

  if(isSorted(A)):
    print("SUCCESS! This universe survives.")
    return A
  else:
    destroyUniverse()

def main():
    array = [int(i) for i in input("Enter the array (space seperated): ").split()]
    array = quantumBogoSort(array)
    print("Your sorted array is:", array)


if __name__ == "__main__":
    main()
