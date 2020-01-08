class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        self.pos = 0
        return self.dfs(S, 0)

    def dfs(self, s, depth):
        if self.pos == len(s): return None
        # remove '--'
        self.pos += depth
        # get number
        num = 0
        while self.pos < len(s) and s[self.pos] != '-':
            num = num * 10 + int(s[self.pos])
            self.pos += 1
        root = TreeNode(num)
        nextd = self.getnextdepth(s)
        # 建立左子树,用深度控制是否建立左子树
        if nextd == depth+1:
            root.left = self.dfs(s, depth+1) 
        nextd = self.getnextdepth(s)
        # 建立右子树，用深度控制是否建立右子树
        if nextd == depth+1:
            root.right = self.dfs(s, depth+1)
        return root
    
    def getnextdepth(self, s):
        count = 0
        pos = self.pos
        while pos < len(s) and s[pos] == '-':
            count += 1
            pos += 1
        return count