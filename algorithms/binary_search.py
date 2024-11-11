from math import floor as mfloor

def binary_search(A: list, s: int):
  n = len(A)
  l, r = 0, n - 1
  while l <= r:
    m = mfloor((r + l) / 2)
    if A[m] > s: 
      r = m - 1
    elif A[m] < s: 
      l = m + 1
    elif A[m] == s: 
      return m
  return -1

if __name__ == "__main__":
  A = [3, 7, 12, 18, 24, 39, 43, 69, 81, 420]
  m = binary_search(A, 69) # 7
  print(m)
