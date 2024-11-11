def bubble_sort(A: list):
  n = len(A)
  for i in range(n-1):
    swapped = False
    for j in range(n-i-1):
      if A[j] > A[j+1]:
        A[j], A[j+1] = A[j+1], A[j]
        swapped = True
    if not swapped:
      break

if __name__ == "__main__":
  A = [4, 2, 8, 1, 9, 7, 3]
  print(A)
  bubble_sort(A)
  print(A)
