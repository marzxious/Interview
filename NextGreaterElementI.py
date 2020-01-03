class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # create 单调递减栈 for nums2, 
        d = {}
        n = len(nums2)
        stack = []
        for i in range(n-1, -1, -1):
            # 把不满足单调递减栈条件的元素pop 出来
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