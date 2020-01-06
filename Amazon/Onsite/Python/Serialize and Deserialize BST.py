# Serialize and Deserialize Binary Search Tree,
# The encoded string should be as compact as possible.
# To serialize a binary tree means to

# Encode tree structure.

# Encode node values.

# Choose delimiters to separate the values in the encoded string.
# Definition for a binary tree node.



class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 都用先序遍历
class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        :type root: TreeNode
        :rtype: str
        """
        res = self.preorder(root)
        ans = ','.join(res)
        return ans
    
    def preorder(self, root): # Root, L, R
        if root is None: return []
        left = self.preorder(root.left)
        right = self.preorder(root.right)
        return [str(root.val)] + left + right
                
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        :type data: str
        :rtype: TreeNode
        """
        if len(data) == 0: return None
        data = map(int, data.split(','))
        data = collections.deque(data)
        return self.preorder(data, float('-inf'), float('inf'))
        
    def preorder(self, data, l, u): # 从开始处理，按照Root, L, R
        if len(data) == 0 or not l < data[0] < u: return None
        val = data.popleft()
        root = TreeNode(val)
        root.left = self.preorder(data, l, val)
        root.right = self.preorder(data, val, u)
        return root
        
# 后序遍历 + 先序遍历
class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        :type root: TreeNode
        :rtype: str
        """
        res = self.postorder(root)
        ans = ','.join(res)
        return ans
    
    def postorder(self, root): # L, R, Root
        if root is None: return []
        left = self.postorder(root.left)
        right = self.postorder(root.right)
        return left + right + [str(root.val)]
                
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        :type data: str
        :rtype: TreeNode
        """
        if len(data) == 0: return None
        data = map(int, data.split(','))
        return self.preorder(data, float('-inf'), float('inf'))
        
    def preorder(self, data, l, u): # 从结尾开始处理，按照Root, R, L
        if len(data) == 0 or not l < data[-1] < u: return None
        val = data.pop()
        root = TreeNode(val)
        root.right = self.preorder(data, val, u)
        root.left = self.preorder(data, l, val)
        return root
    
# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
