class Solution:
    """
    @param: words: a set of words without duplicates
    @return: all word squares
    """
    def wordSquares(self, words):
        # DFS
        if len(words) == 0: return []
        # prefix hash map
        d = collections.defaultdict(set)
        for word in words:
            for i in range(len(word)+1):
                d[word[:i]].add(word)
        
        self.sol = []
        n = len(words[0])
        self.dfs(n, 0, d, [])
        return self.sol
    
    def dfs(self, n, row, d, res):
        if row == n:
            self.sol.append(res[:])
            return 
        # consturct head
        head = ''
        for r in range(row):
            head += res[r][row]
        
        for w in d[head]:
            res.append(w)
            self.dfs(n, row + 1, d, res)
            res.pop()