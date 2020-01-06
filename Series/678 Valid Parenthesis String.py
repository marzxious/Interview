"""
https://leetcode.com/problems/valid-parenthesis-string/

Example 1:
Input: "()"
Output: True

Example 2:
Input: "(*)"
Output: True

難點: 星號可以代表( or )

思路: Greedy, 用3 個counter 代表左括號 星號 右括號, 如果左括號消耗完了就消耗星號 如果連星號也沒有的話 就是一個不valid的右括號 right+1
遍歷完最後沒被消耗的左括號 右括號 就是不成對的


"""

def helper(self, s, arr):
    star, left, right = 0, 0, 0

    for i in s:
        if i=='*':
            star+=1
        elif i==arr[0]:
            left+=1
        elif i==arr[1] and left>0:
            left-=1
        elif i==arr[1] and star>0:
            star-=1
        else:
            right+=1
            if star==0 and left==0 and right>0:
                return False
    if arr[0]=="(":
        return self.helper(s[::-1], [")","("])
    else:
        return True


