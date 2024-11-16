def merge(l, r):
  res = []
  i, j = 0, 0

  while i < len(l) and j < len(r):
    if l[i] <= r[j]:
      res.append(l[i])
      i += 1
    else:
      res.append(r[j])
      j += 1

  while i < len(l):
    res.append(l[i])
    i += 1

  while j < len(r):
    res.append(r[j])
    j += 1

  return res

def merge_sort(A: list):
  n = len(A)

  if n <= 1: 
    return A

  m = n//2
  l = A[:m]
  r = A[m:]

  l = merge_sort(l)
  r = merge_sort(r)

  return merge(l, r)

if __name__ == "__main__":
  A = [3, 5, 1, 8, 189, 39, 18, 238, 2, 9, 69]

  print("before:", A)
  A = merge_sort(A)
  print("after:", A)
