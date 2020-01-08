"""
https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

思路: 如何計算當前的括號不合理 --> 任意時候 右邊括號數不能大於左邊話號數.
使用兩個計數器 l, r 來計算遇到的括號, 如果遇到左括號 l+1, 如果遇到右邊括號 並且l == 0 (代表沒有括號可以匹配), 那麼r+1, 否則消耗一個左括號 l -1

最終不成對的括號數 l + r 則是需要刪減的括號.

"""
def minAddToMakeValid(self, S):

    if not S:
        return 0
    l, r = 0, 0
    for i in S:
        if i=="(":
            l+=1
        elif i==")" and l>0:
            l-=1
        else:
            r+=1
    return l+r


