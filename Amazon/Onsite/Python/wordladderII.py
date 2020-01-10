class Solution:
    def findLadders(self, start, end, dict):
        # BFS + DFS
        # convert dict to dictionary
        self.word = [chr(ord('a')+c) for c in range(26)]
        d = set(dict)
        d.add(end)
        dist = self.bfs(start, end, d)
        self.sol = []
        self.backtrack(dist, end, start, d, [end])
        return self.sol
        
    def backtrack(self, dist, cur, start, d, res):
        # start from end word, do dfs
        if cur == start:
            self.sol.append(res[::-1])
            return 
        for nbr in self.getNbrs(cur, dist):
            if dist[nbr] == dist[cur] - 1: # 利用距离递减回溯
                res.append(nbr)
                self.backtrack(dist, nbr, start, d, res)
                res.pop()
    
    def bfs(self, start, end, d):
        dist = {start: 0}
        q = collections.deque([start])
        level = 1
        while q:
            size = len(q)
            for _ in range(size):
                cur = q.popleft()
                if cur == end:
                    return dist
                nbrs = self.getNbrs(cur, d)
                for nbr in nbrs:
                    if nbr not in dist:
                        dist[nbr] = level
                        q.append(nbr)
            level += 1