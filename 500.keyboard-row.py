#
# @lc app=leetcode id=500 lang=python3
#
# [500] Keyboard Row
#

# @lc code=start
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        dic = ["qwertyuiop", "asdfghjkl", "zxcvbnm"]
        res = []
        for word in words:
            for i in range(3):
                if word[0].lower() in dic[i]:
                    pos = True
                    for c in word.lower():
                        if not c in dic[i]:
                            pos = False
                            break
                    if pos:
                        res.append(word)
                    break
        return res
# @lc code=end

