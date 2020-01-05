#BFS

class Codec:
    def serialize(self, root: 'Node') -> str:
        # n-ary traversal, BFS, DFS
        if not root: return ''
        res = []
        q = collections.deque([root])
        while q:
            node = q.popleft()
            if node != '#':
                res.append(str(node.val))
                for child in node.children:
                    q.append(child)
                q.append('#')
            else:
                res.append('#') # 这一家的兄弟访问完了
        print(res)
        return ','.join(res)
        
    def deserialize(self, data):
        if len(data) == 0: return None
        data = data.split(',')
        root = Node(int(data[0]), [])
        idx = 1
        q = collections.deque([root])
        while q:
            cur = q.popleft()
            while data[idx] != '#':
                child = Node(int(data[idx]),[])
                cur.children.append(child)
                q.append(child)
                idx += 1
            idx += 1
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