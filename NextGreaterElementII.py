class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        # 弄成两份，第二份建立单调栈
        stack = []
        n = len(nums)
        for i in range(n-1, -1, -1):
            while stack and stack[-1] <= nums[i]:
                stack.pop()
            stack.append(nums[i])
        # 
        res = []
        for i in range(n-1, -1, -1):
            while stack and stack[-1] <= nums[i]:
                stack.pop()
            if len(stack) == 0:
                res.append(-1)
            else:
                res.append(stack[-1])
            stack.append(nums[i])
        return res[::-1]