"""
https://leetcode.com/problems/generate-parentheses/

[高頻]
給定一個n, 產生所有n個pair 且valid的括號
ex n = 3, ((())), ()()() ...etc.

暴力深搜 : 可用的左括號有n個 可用的右括號有n個 在每個位置嘗試放入左括號 || 右括號
剪枝     : 任何時刻 左括號數不可<右括號.

時間複雜度 ~4^n 樹的深度可以到2^n

"""

def generateParenthesis(self, n):
    if n<=0:
        return [""]
    res = []
    self.dfs(n, n, "", res)
    return res

def dfs(self, left, right, temp, res):
    if left==0 and right==0:
        res.append(temp)
        return res
    if left>right or left<0 or right<0:
        return
    if left-1<=right:
        self.dfs(left-1, right, temp+"(", res)
    if left<=right-1:
        self.dfs(left, right-1, temp+")", res)


