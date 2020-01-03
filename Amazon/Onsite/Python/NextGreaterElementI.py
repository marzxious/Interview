class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # create 单调递减栈 for nums2, 
        # [1,3,4,2] 
        # for 2: the stack is empty, d[2] = -1, push 2 to stack
        # for 4: the stack top is 2, smaller than 4, pop it out.the stack is empty, d[4] = -1, push 4 to stack
        # for 3: the stack top is 4, larger than 3, d[4] = 3, push 3 to stack, 
        # for 1: the stack top is 3, larger than 1, d[1] = 3, push 1 to stack,# [1,3,4,2] 
        d = {}
        n = len(nums2)
        stack = []
        for i in range(n-1, -1, -1):
            # 把不满足单调递栈条件的元素pop 出来
            while stack and stack[-1] <= nums2[i]:
                stack.pop()
            if len(stack) == 0:
                d[nums2[i]] = -1
            else: # 栈顶就是要找的答案
                d[nums2[i]] = stack[-1] 
            stack.append(nums2[i])
            
        res = []
        for c in nums1:
            res.append(d[c])
        return res