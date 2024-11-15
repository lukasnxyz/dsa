def partition(A):
  n = len(A)
  p = n-1
  i = -1

  for j in range(n-2):
    if A[j] <= A[p]:
      i += 1
      A[i], A[j] = A[j], A[i]
  i += 1
  A[i], A[n-1] = A[n-1], A[i]
  return A

def quick_sort(A: list):
  n = len(A)
  if n > 1:
    A = partition(A)
    return quick_sort(A[:len(A)]) + A[len(A)] + quick_sort(A[len(A)+1:n-1])
  else:
    return A

if __name__ == "__main__":
  A = [3, 5, 1, 8, 189, 39, 18, 238, 2, 9, 69]

  print("before:", A)
  quick_sort(A)
  print("after:", A)
