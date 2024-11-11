def fib(n: int):
  f = [0, 1]
  print(f[0])
  print(f[1])
  for i in range(2, n):
    f.append(f[i-1] + f[i-2])
    print(f[i])

if __name__ == "__main__":
  fib(15)
