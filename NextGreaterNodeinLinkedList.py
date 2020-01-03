# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        # convert linked list to array, user extra space
        nums = []
        cur = head
        while cur:
            nums.append(cur.val)
            cur = cur.next
        # monotonic decreasing stack, same as 
        res = []
        stack = []
        n = len(nums)
        for i in range(n-1, -1, -1):
            while stack and stack[-1] <= nums[i]:
                stack.pop()
            if len(stack) == 0:
                res.append(0)
            else:
                res.append(stack[-1])
            stack.append(nums[i])
        return res[::-1]
                