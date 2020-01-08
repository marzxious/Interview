class Solution:
    def findAllConcatenatedWordsInADict(self, words):
        # dfs
        d = set(words)
        ans = []
        for word in words:
            if self.dfs(word, 0, d, []):
                ans.append(word)
        return ans
    
    def dfs(self, word, start, d, res):
        if start == len(word):
            if len(res) > 1:  return True
            return False
        for i in range(start, len(word)):
            if word[start:i+1] in d:
                res.append(word[start:i+1])
                if self.dfs(word, i+1, d, res):
                    return True
                res.pop()
        return False

class Solution:
    def findAllConcatenatedWordsInADict(self, words):
        # dfs + memo
        d = set([word for word in words if len(word) > 0] ) #去掉空串
        ans = []
        memo = {}
        for word in words:
            if self.dfs(word, d, memo):
                ans.append(word)
        return ans
    
    def dfs(self, word, d, memo):
        if word in memo: return memo[word]
        for i in range(len(word)):
            if word[:i+1] in d: 
                if word[i+1:] in d or self.dfs(word[i+1:], d, memo): # 等于两个单词
                    memo[word] = True
                    return True
        memo[word] = False
        return False