class Queue:
  def __init__(self):
    self.q = []

  def enqueue(self, d: int):
    self.q.append(d)

  def dequeue(self):
    d = self.q[0]
    del self.q[0]
    return d

  def qprint(self):
    for q in self.q:
      print(q)

if __name__ == "__main__":
  q = Queue()

  q.enqueue(1)
  q.enqueue(2)
  q.enqueue(3)
  q.enqueue(4)
  q.qprint()
  print()
  q.dequeue()
  q.qprint()
