"""
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

難點: 要從字串裡面移除不正確的括號

Solution 1:
    Stack + String Builder
    用一個index_to_remove 去記住所有不合理的括號下標.

    用stack去標記所有的左括號下標, 如果遇到一個右括號 則彈出一個左邊括號匹配
    當stack為空(沒有可以匹配的左括號) 則標記當前的index下標(position of invalid)
    --> 當前的index記住的是invalid的右括號無法匹配左括號.
    當遍歷完數組, Stack裡面剩下的是 無法match 右括號的左括號, 把這些下標一併加入inval    id indexes

"""

def minRemoveToMakeValid(self, s):

    indexes_to_remove = set()
    stack = []
    for i, c in enumerate(s):
        if c not in "()":
            continue
        if c == "(":
            stack.append(i)
        elif not stack:
            indexes_to_remove.add(i)
        else:
            stack.pop()
    indexes_to_remove = indexes_to_remove.union(set(stack))
    string_builder = []
    for i, c in enumerate(s):
        if i not in indexes_to_remove:
            string_builder.append(c)
    return "".join(string_builder)


"""
Solution 2:
    Two Pass String Builder
    第一次遍歷 從左往右遍歷一次 找不匹配左括號 ( 的右括號 )
    第二次遍歷 把字串反過來 找不匹配右括號 ) 的左括號 (

"""

def minRemoveToMakeValid(self, s):
    def delete_invalid_closing(string, open_symbol, close_symbol):
        sb = []
        balance = 0
        for c in string:
            if c == open_symbol:
                balance += 1
            if c == close_symbol:
                if balance == 0:
                    continue
                balance -= 1
            sb.append(c)
        return "".join(sb)

    s = delete_invalid_closing(s, "(", ")")
    s = delete_invalid_closing(s[::-1], ")", "(")
    return s[::-1]



