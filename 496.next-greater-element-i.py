#
# @lc app=leetcode id=496 lang=python3
#
# [496] Next Greater Element I
#

# @lc code=start
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        st = []
        n = len(nums2)
        dic = {}
        for i in range(n):
            while len(st) != 0 and st[-1] < nums2[i]:
                dic[st[-1]] = nums2[i]
                st.pop()
            st.append(nums2[i])
        #print(dic)
        res = []
        for i in nums1:
            if i in dic:
                res.append(dic[i])
            else:
                res.append(-1)
        return res
# @lc code=end

