class Stack:
  def __init__(self):
    self.stack = []

  def push(self, d: int):
    self.stack.insert(0, d)

  def pop(self):
    d = self.stack[0]
    del self.stack[0]
    return d

  def stack_print(self):
    for e in self.stack:
      print(e)

if __name__ == "__main__":
  st = Stack()

  st.push(1)
  st.push(2)
  st.push(3)
  st.push(4)
  st.stack_print()
  print()
  st.pop()
  st.stack_print()
