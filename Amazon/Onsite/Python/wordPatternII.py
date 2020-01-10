class Solution:
    """
    @param pattern: a string,denote pattern string
    @param str: a string, denote matching string
    @return: a boolean
    """
    def wordPatternMatch(self, p, s):
        # True or False 型的 backtracking
        return self.dfs(p, s, {}) # True or False 型的 backtracking
        
    def dfs(self, p, s, d):
        if len(p) == 0: return len(s) == 0
        c = p[0]
        if c in d: # 第一个char 已经遇到过了，接着递归就可以了
            if s.startswith(d[c]):
                l = len(d[c])
                return self.dfs(p[1:], s[l:], d)
            else:
                return False
        else: # 第一个char 没有遇到过，穷举所有可能分割
            for i in range(1, len(s)+1):
                if s[:i] in d.values(): continue # 已经用过了，不能再用
                d[c] = s[:i]
                if self.dfs(p[1:], s[i:], d): # True or False 型的 backtracking 套路
                    return True
                del d[c]
            return False