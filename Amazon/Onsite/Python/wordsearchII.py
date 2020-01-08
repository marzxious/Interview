class Solution:
    def wordSearchII(self, board, words):
        # build prefix hash set
        row, col = len(board), len(board[0])
        preSet = set()
        wordSet = set(words)
        for word in words:
            for i in range(len(word)):
                preSet.add(word[:i+1])
        self.sol = set()
        for i in range(row):
            for j in range(col):
                # search based on prefix hash set
                if board[i][j] in preSet:
                    self.dfs(board, i, j, preSet, wordSet, board[i][j], set([(i,j)]))
        return list(self.sol)
        
    def dfs(self, board, x, y, preSet, wordSet, res, seen):
        row, col = len(board), len(board[0])
        if res in wordSet: 
            self.sol.add(''.join(res[:]))
        for i,j in [(1,0),(0,1),(-1,0),(0,-1)]:
            nx, ny = x+i, y+j
            if 0<=nx<row and 0<=ny<col and res + board[nx][ny] in preSet and (nx,ny) not in seen:
                seen.add((nx,ny))
                self.dfs(board, nx, ny, preSet, wordSet, res + board[nx][ny], seen)
                seen.remove((nx,ny))

class TrieNode:
    def __init__(self):
        self.children = {}
        self.isWord = False
class Trie:
    def __init__(self):
        self.root = TrieNode()
    def addword(self, word):
        cur = self.root
        for c in word:
            if c not in cur.children:
                cur.children[c] = TrieNode()
            cur = cur.children[c]
        cur.isWord = True
class Solution:
    def wordSearchII(self, board, words):
        # build trie
        row, col = len(board), len(board[0])
        t = Trie()
        for word in words:
            t.addword(word)
        self.sol = set()
        for i in range(row):
            for j in range(col):
                # search based on trie
                if board[i][j] in t.root.children:
                    self.dfs(board, i, j, t.root.children[board[i][j]], [board[i][j]], set([(i,j)]))
        return list(self.sol)
        
    def dfs(self, board, x, y, node, res, seen):
        row, col = len(board), len(board[0])
        if node.isWord: self.sol.add(''.join(res[:]))
        for i,j in [(1,0),(0,1),(-1,0),(0,-1)]:
            nx, ny = x+i, y+j
            if 0<=nx<row and 0<=ny<col and board[nx][ny] in node.children and (nx,ny) not in seen:
                seen.add((nx,ny))
                res.append(board[nx][ny])
                self.dfs(board, nx, ny, node.children[board[nx][ny]], res, seen)
                res.pop()
                seen.remove((nx,ny))