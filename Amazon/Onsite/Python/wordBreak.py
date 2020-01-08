class Solution:
    def wordBreak(self, s, dict):
        # dfs
        d = set(dict)
        maxlen = max([len(w) for w in dict]) if len(dict) else 0
        return self.dfs(s, 0, d, maxlen)
    
    def dfs(self, s, start, d, maxlen):
        if start == len(s):
            return True
        for i in range(start, len(s)):
            if i+1 - start > maxlen: break
            if s[start:i+1] in d:
                if self.dfs(s, i+1, d, maxlen):
                    return True
        return False