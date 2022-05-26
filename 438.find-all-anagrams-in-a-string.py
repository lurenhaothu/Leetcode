#
# @lc app=leetcode id=438 lang=python3
#
# [438] Find All Anagrams in a String
#

# @lc code=start
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(s) < len(p): return []
        res = []
        dictS = {}
        dictP = {}
        for c in p:
            if not c in dictP:
                dictP[c] = 0
            dictP[c] += 1;
        # print(dictP)
        for i in range(len(p)):
            if not s[i] in dictS:
                dictS[s[i]] = 0
            dictS[s[i]] += 1;
        #print(0)
        if dictS == dictP : res.append(0)
        for i in range(len(p) , len(s)):
            if not s[i] in dictS:
                dictS[s[i]] = 0
            dictS[s[i]] += 1
            dictS[s[i - len(p)]] -= 1
            if dictS[s[i - len(p)]] == 0:
                dictS.pop(s[i - len(p)])
            if dictS == dictP : res.append(i - len(p) + 1)
        return res
        
# @lc code=end

