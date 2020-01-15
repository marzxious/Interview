# DFS - 花花匠

def removeInvalidParentheses(self, s):     
    
    #計算左右括號不合理的個數
    left, right = 0, 0   #left/right : no of invalid left/right parenthese
    for c in s:
        if c == '(':
            left+=1
        elif c==')' and left>0:
            left-=1
        elif c==')' and left==0:
            right +=1
    res = []
    self.dfs(0, left, right, s, res)
    if not res:
        return [""]
    return res

def isValid(self, s):
    l = 0
    for i in s:
        if i =='(':
            l+=1
        elif i==')' and l>0:
            l-=1
        elif i==')' and l==0:
            return False
    return True

def dfs(self, start, left, right, s, res):#注意这里的index跟长度没有关系

    if left==0 and right==0:    
        if self.isValid(s):
            res.append(s)


    for index in range(start, len(s)): 
        if index>start and s[index]==s[index-1]:
            continue
        #去重	

        if s[index]==')' and right>0:                
            self.dfs(index, left, right-1, s[0:index]+s[index+1:], res) 
        if s[index]=='(' and left>0:                
            self.dfs(index, left-1, right, s[0:index]+s[index+1:], res)
        #注意index+1是错的


