#
# @lc app=leetcode id=479 lang=python3
#
# [479] Largest Palindrome Product
#

# @lc code=start
class Solution:
    def largestPalindrome(self, n: int) -> int:
        def isPalindrome(i):
            s = str(i)
            for j in range(len(s) // 2 + 1):
                if s[j] != s[-j - 1]:
                    return False
            return True
        res = 12
        k = int('9' * n)
        for s in range(k + k, 0, -1):
            if s % 10 != 0 and s % 10 != 6 and s % 10 != 4:
                continue
            for i in range(k, s - k, -1):
                if ((i % 10) * (s - i) % 10) % 10 != 9:
                    continue
                if i < s - i:
                    break
                res = i * (s - i)
                if isPalindrome(res):
                    return res % 1337
                    break
            if isPalindrome(res):
                break
# @lc code=end

