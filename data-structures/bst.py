class Node:
  def __init__(self, key):
    self.key = key
    self.left = None
    self.right = None

class BST:
  def __init__(self):
    self.root = None

  def insert(self, key):
    self.root = self._insert_recursive(self.root, key)

  def _insert_recursive(self, root, key):
    if root is None:
      return Node(key)
    if key < root.key:
      root.left = self._insert_recursive(root.left, key)
    else:
      root.right = self._insert_recursive(root.right, key)
    return root
