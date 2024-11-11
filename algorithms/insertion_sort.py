def insertion_sort(a: list):
  n = len(a)
  for i in range(1, n):
    h = a[i]
    j = i-1
    while a[j] > h and j >= 0:
      a[j+1] = a[j]
      j -= 1
    a[j+1] = h

if __name__ == "__main__":
  arr = [5, 2, 4, 6, 1, 3]

  print("before:", arr)
  insertion_sort(arr)
  print("after:", arr)
