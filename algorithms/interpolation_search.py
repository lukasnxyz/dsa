def interpolation_search(A: list, l: int, h: int, x: int):
  if l <= h and x >= A[l] and x <= A[h]:
    t = l + ((h-l) // (A[h] - A[l]) * (x - A[l]))
    if x == A[t]: return t
    if A[t] < x: return interpolation_search(A, t+1, h, x)
    if A[t] > x: return interpolation_search(A, l, t-1, x)
  return -1

if __name__ == "__main__":
  A = [1, 2, 3, 4, 5, 6, 8, 29, 138, 4892, 38490, 98399]
  i = interpolation_search(A, 0, len(A)-1, 4)
  print(f"index: {i}")
