class Node:
  def __init__(self, data: int):
    self.data: int = data
    self.next: Node = None

class LL:
  def __init__(self):
    self.head = None

  def insert_head(self, data: int):
    new_node = Node(data)
    new_node.next = self.head
    self.head = new_node
  
  def insert_end(self, data: int):
    new_node = Node(data)
  
    if self.head is None:
      self.head = new_node
      return
  
    curr = self.head
    # I always get this wrong, has to be curr.next not curr
    while curr.next: 
      curr = curr.next
    curr.next = new_node
  
  def lprint(self):
    curr = self.head
    while curr:
      print(curr.data)
      curr = curr.next

if __name__ == "__main__":
  list = LL()

  list.insert_end(1)
  list.insert_end(2)
  list.insert_end(3)
  list.insert_end(4)
  list.insert_end(5)

  list.lprint()
