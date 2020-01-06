# Serialize and Deserialize Binary Tree,
# To serialize a binary tree means to

# Encode tree structure.

# Encode node values.

# Choose delimiters to separate the values in the encoded string.
# 解题思路: 
# 方法1：
# BFS，level order traversal, 空节点也入队列，遇到空节点写入‘#‘，遇到数字写入值
# 	   3
# 	 /  \
# 	9    20
#  / \  /  \
# #	 # 15   7
#     /  \  / \
# 		#	 #  #  #
# {3,9,20,#,#,15,7,#,#,#,#}


# 方法1: BFS
# 序列化，反序列化二叉树或者BST都可以用BFS

# 序列化的时候进行BFS，从队列中取一个node，如果是空节点，在字符串写入‘#’，
# 反之写入node的值，如果node不为空，把左右儿子入队列

# （最后一步空间优化），求出字符串以后用while 循环把由于最后一层的空节点而记录的‘#’ 删掉

# 反序列化，进行正常BFS操作，遇到数字，生成一个node并写入到队列，遇到‘#’，直接跳过。

# （因为进行了空间优化，所以每次都需要判断字符串是不是处理完了，因为最后队列里不一定为空，
# 而是还存有最后一层的节点）
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Codec:
    def serialize(self, root):
        # BFS, mark None as #, 入队列的时候写字符串
        if root is None: return ''
        q = collections.deque([root])
        res = [str(root.val)]
        while q:
            cur = q.popleft()
            if cur.left:
                res.append(str(cur.left.val))
                q.append(cur.left)
            else:
                res.append('#')
            if cur.right:
                res.append(str(cur.right.val))
                q.append(cur.right)
            else:
                res.append('#')
        return ','.join(res)            

    def deserialize(self, data):
        if len(data) == 0: return None
        L = data.split(',')
        data = collections.deque(L)
        root = TreeNode(int(data.popleft()))
        q = collections.deque([root])
        while q:
            cur = q.popleft()
            if data[0] != '#':
                cur.left= TreeNode(str(data.popleft()))
                q.append(cur.left)
            else:
                data.popleft() #pop '#'
            if data[0] != '#':
                cur.right= TreeNode(str(data.popleft()))
                q.append(cur.right)
            else:
                data.popleft() #pop '#'
        return root

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        self.res = []
        self.dfs(root)
        ans = ','.join(self.res)
        return ans
        
    def dfs(self, root):
        if root is None:
            self.res.append('#') #如果是空节点，在字符串写入‘#’
            return
        self.res.append(str(root.val))
        self.dfs(root.left)
        self.dfs(root.right)
        
    def deserialize(self, data):
        L = data.split(',')
        q = collections.deque(L)
        return self.helper2(q)
        
    def helper2(self, q):
        val = q.popleft()
        if val == '#':
            return None
        root = TreeNode(int(val))
        root.left = self.helper2(q)
        root.right = self.helper2(q)
        return root
    