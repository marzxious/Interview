# BST
class Node:
    def __init__(self, start, end):
        self.start, self.end = start, end
        self.left = self.right = None

class MyCalendar(object):
    def __init__(self):
        self.root = None
    def book(self, start, end):
        if self.root is None:
            self.root = Node(start, end)
            return True
        return self.insert(self.root, Node(start, end))
        
    def insert(self, root, node):
        if node.end <= root.start:
            # left
            if root.left is None:
                root.left = node
                return True
            return self.insert(root.left, node)
        elif node.start >= root.end:
            if root.right is None:
                root.right = node
                return True
            return self.insert(root.right, node)
        else:
            return False    