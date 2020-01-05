#BFS
class Codec:
    def serialize(self, root: 'Node') -> str:
        # n-ary traversal, BFS, DFS
        if not root: return ''
        res = []
        q = collections.deque([root])
        res = [str(root.val)]
        while q:
            node = q.popleft()
            for child in node.children:
                res.append(str(child.val))
                q.append(child)
            res.append('#') 
        return ','.join(res)
        
    def deserialize(self, data):
        if len(data) == 0: return None
        data = data.split(',')
        data = collections.deque(data)
        root = Node(int(data.popleft()), [])
        q = collections.deque([root])
        while q:
            cur = q.popleft()
            while data[0] != '#': # 遇到 end of child marker的时候停止
                child = Node(int(data.popleft()),[])
                cur.children.append(child)
                q.append(child)
            data.popleft() # 去掉 ‘#’
        return root

## DFS
class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        :type root: Node
        :rtype: str
        """        
        if root is None: return ''
        res = self.serial_tree(root)
        print(res)
        return ','.join(res)
        
    def serial_tree(self,node):
        if node is None: return 
        res = []
        res.append(str(node.val))
        for c in node.children:
            res += self.serial_tree(c)
        res.append('#')
        return res
        
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        :type data: str
        :rtype: Node
        """
        if len(data) ==0: return None
        datastr = collections.deque(data.split(','))
        root = self.deserial_tree(datastr)
        return root
    def deserial_tree(self, datastr):
        if len(datastr) == 0: return None
        node = Node(int(datastr.popleft()), [])
        while datastr[0] != '#': # add child nodes with subtrees
            child = self.deserial_tree(datastr) 
            node.children.append(child)
        datastr.popleft()  # discard the "#"
        return node