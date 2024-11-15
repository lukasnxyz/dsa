#def merge(l: list, r: list):
#  n = len(l) + len(r)
#  R = []
#  il, ir = 0, 0
#
#  for i in range(n):
#    if l[il] <= r[ir]:
#      R.append(l[il])
#      il += 1
#    else:
#      R.append(r[ir])
#      ir += 1
#
#  return R

def merge(left, right):
    result = []
    i, j = 0, 0
    
    # Compare elements from both lists and add the smaller one to the result
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    
    # Add any remaining elements from left list
    result.extend(left[i:])
    
    # Add any remaining elements from right list
    result.extend(right[j:])
    
    return result

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
  merge_sort(A)
  print("after:", A)
