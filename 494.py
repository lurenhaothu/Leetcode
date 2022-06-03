class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        if n == 1:
            if nums[0] != 0 and abs(nums[0]) == abs(target):
                return 1
            elif nums[0] == 0 and target == 0:
                return 2
            else:
                return 0
        nums1 = nums[:n // 2]
        nums2 = nums[n // 2:]
        def getCand(nums):
            if len(nums) == 1:
                if nums[0] != 0:
                    return {nums[0] : 1, -nums[0] : 1}
                else:
                    return {0 : 2}
            else:
                prev = getCand(nums[:-1])
                res = {}
                for i in prev:
                    if i + nums[-1] in res:
                        res[i + nums[-1]] += prev[i]
                    else:
                        res[i + nums[-1]] = prev[i]
                    if i - nums[-1] in res:
                        res[i - nums[-1]] += prev[i]
                    else:
                        res[i - nums[-1]] = prev[i]
                return res
        dic1 = getCand(nums1)
        dic2 = getCand(nums2)
        res = 0
        for i in dic1:
            if target - i in dic2:
                res += dic1[i] * dic2[target - i]
        return res