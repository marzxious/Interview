class Solution:
    """
    @param: start: a string
    @param: end: a string
    @param: dict: a set of string
    @return: An integer
    """
    def ladderLength(self, start, end, di):
        # BFS
        # list to set
        d = set(di)
        d.add(end)
        q = collections.deque([start])
        seen = set([start])
        level = 1
        while q:
            size = len(q)
            for _ in range(size):
                cur = q.popleft()
                if cur == end: return level
                nbrs = self.getNbrs(cur,d)
                for w in nbrs:
                    if w not in seen:
                        seen.add(w)
                        q.append(w)
            level += 1
        return 0
        
    def getNbrs(self,cur,d):
        res = []
        for i in range(len(cur)):
            for x in 'abcdefghijklmnopqrstuvwxyz':
                nw = cur[:i]+x+cur[i+1:]
                if nw in d: # find nbrs from the dict by changing one char
                    res.append(nw)
        return res