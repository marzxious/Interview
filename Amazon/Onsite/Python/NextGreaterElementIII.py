class Solution:
    def nextGreaterElement(self, n: int) -> int:
        # calculate next permutation
        # 1. from right to left find pivot, 2. find switch point. 3. swap, 4. then sort element after pivot
        s = list(str(n))
        n = len(s)
        if n <= 1: return -1
        pivot = None
        for i in range(n-2, -1, -1):
            if s[i] < s[i+1]:
                pivot = i
                break
        if pivot is None: return -1
        for i in range(n-1, -1, -1):
            if s[i] > s[pivot]:
                switch = i
                break
        # swap
        s[switch], s[pivot] = s[pivot], s[switch]
        # sort
        tmp = s[pivot+1:]
        tmp.sort()
        res = s[:pivot+1] + tmp
        if int(''.join(res)) > 2**31:
            return -1
        else:
            return int(''.join(res))