#
# @lc app=leetcode id=472 lang=python3
#
# [472] Concatenated Words
#

# @lc code=start
class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        wordDict = {}
        conDict = {}
        for word in words:
            wordDict[word] = 1
        def isCon(word, first):
            if not first:
                if word == '' or word in wordDict:
                    return True
            n = len(word)
            for i in range(n - 1):
                if word[0:i + 1] in wordDict and isCon(word[i + 1:], False):
                    #conDict[word[i + 1:]] = 1
                    return True
            return False
        res = []
        for word in words:
            if isCon(word, True):
                res.append(word)
        return res
# @lc code=end

