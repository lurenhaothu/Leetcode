class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        resdic = {}
        def DFS(cur, index):
            if len(cur) >= 2:
                resdic[str(cur)] = cur.copy()
            if index == len(nums):
                return
            for i in range(index, len(nums)):
                if len(cur) == 0 or cur[-1] <= nums[i]:
                    cur.append(nums[i])
                    DFS(cur, i + 1)
                    cur.pop()
        cur = []
        DFS(cur, 0)
        res = []
        for i in resdic:
            res.append(resdic[i])
        return res