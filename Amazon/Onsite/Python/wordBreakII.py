class Solution:
    def wordBreak(self, s, wordDict):
        # DFS
        d = set(wordDict)
        maxlen = max([len(w) for w in wordDict]) if len(wordDict) else 0
        self.sol = []
        memo = {}
        res = self.dfs(s, 0, d, [], maxlen, memo)
        return [' '.join(w) for w in res]
        
    def dfs(self, s, start, d, res, maxlen, memo):
        if start in memo: return memo[start]
        if start == len(s): 
            return [[]]
        ans = []
        for i in range(start, len(s)):
            if i + 1 - start > maxlen: break
            if s[start:i+1] in d:
                tmp = self.dfs(s, i+1, d, res, maxlen, memo)
                for x in tmp:
                    ans.append([s[start:i+1]] + x)
        memo[start] = ans
        return ans


class Solution:
    """
    @param: s: A string
    @param: wordDict: A set of words.
    @return: All possible sentences.
    """
    def wordBreak(self, s, wordDict):
        # dfs+ memo
        memo = {}
        d = set(wordDict)
        return self.dfs(s, d, memo)
        
    def dfs(self, s, d, memo):
        if s in memo: return memo[s]
        if len(s) == 0:
            return []
        
        res = []
        for i in range(1, len(s)+1):
            if s[:i] in d: 
                tmp = self.dfs(s[i:], d, memo) # s[i:] == '' return []
                for c in tmp:
                    res.append(s[:i] + ' ' + c)
            if i == len(s):
                if s in d:
                    res.append(s)
        memo[s] = res
        return res