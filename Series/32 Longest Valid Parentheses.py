"""
https://leetcode.com/problems/longest-valid-parentheses/ 

[Hard]

想要确定最长子串，无非就是直接构造子串，要不就是记录下标。 如果是直接构造子串，是”()()”匹配还是”(())”匹配会有区别，怎样构造string又是一个难题。 如果是记录下标，就需要记录子串开头位置，什么时候是子串的开头也是一个难题。

对于记录下标

0 1 2 3

( ( ) ) 遍历的过程中 0, 1依次入栈，到2时弹出1，到3时弹出0，此时最大长度就是3 - 0 + 1 = 4

0 1 2 3

( ) ( )

遍历的过程中 0入栈，到1时弹出0，长度为1 - 0 + 1 = 2 2入栈，到3时弹出2，长度为3 - 2 + 1 = 2

所以对于记录下标的方法，不能计算”()()”这样的匹配的长度，原因是没有记录最开始0的位置，也就是不知道最开始匹配时的位置。 为了解决这个问题， 在栈的首部添加-1，即初始时栈不为空，栈顶为-1，-1表示起始位置 遍历的过程中，遇到”(“，将索引入栈，遇到”)”，从栈顶弹出一个元素，然后计算”)”的下标和此时栈顶元素的差，即为当前匹配的子串长度 如果遇到”)”时栈中为空，那就说明到最左端已经匹配过了，这个长度已经count过了，那需要将当前的下标入栈，作为起始位置


"""

def longestValidParentheses(self, s):

    if not s:
        return 0
    stack = []
    stack.append(-1)
    maxans = 0
    for i, c in enumerate(s):
        if c=='(':
            stack.append(i)
        else:
            stack.pop()
            if not stack:
                stack.append(i)
            else:
                maxans = max(maxans, i-stack[-1])
    return maxans



























