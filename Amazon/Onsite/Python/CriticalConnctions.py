class Solutions: 
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        # tarjan，记录 visitTimeAnyPath 和 visitTime from parent， 每个node 的 visitTimeAnyPath = min(visitTimeAnyPath of its children and itself)
        # 如果 visitTimeAnyPath of child is larger than visitTime of parent, 只能走这条路到那个child， find an edge
        # visitTimeAnyPath: visit time from any path
        # visitTime: visit time through path from its parent
        
        g = collections.defaultdict(list)
        for c in connections: # build graph
            g[c[0]].append(c[1])
            g[c[1]].append(c[0])
        self.seq = 1
        self.sol,self.visitTimeAnyPath,self.visitTime = [], [0] * n, [0] * n
        self.dfs(g, 0, -1) 
        return self.sol
    def dfs(self, g, cur, parent):
        if self.visitTime[cur] > 0: # 已经访问过的节点跳过
            return
        self.visitTime[cur] = self.visitTimeAnyPath[cur] = self.seq # 标记节点的visit time 和 visit time from any path
        self.seq += 1
        for child in g[cur]:
            if child == parent: continue # 不能回头看父亲
            self.dfs(g, child, cur) # 递归处理处理每个儿子
            self.visitTimeAnyPath[cur] = min(self.visitTimeAnyPath[child],self.visitTimeAnyPath[cur]) # 看看有没有更短的路
            if self.visitTimeAnyPath[child] > self.visitTime[cur]: # 如果child只能在父亲之后访问到，说明没有其他路，只能走这条边
                self.sol.append([cur, child])