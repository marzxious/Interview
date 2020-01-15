"""
https://leetcode.com/problems/valid-parentheses/

Input: "()[]{}"
Output: true

Input: "([)]"
Output: false


如果遇到右括號 就去看看stack裡面最後一個是不是matched的左括號
因為有很多不同的括號 用一個hashmap記住每一種右括號對應的左括號. 

返回false 如果不match, or stack遍歷到最後不為空.

"""
def isValid(self, s):   
    if not s:
        return True
    stack = []
    dic = {']':'[', ')':'(', '}':'{' }
    for i in s:
        if i in dic: 
            if stack and stack[-1] == dic[i]:
                stack.pop()
            else:
                return False
        else:
            stack.append(i)
    return not stack


