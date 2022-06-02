#
# @lc app=leetcode id=482 lang=python3
#
# [482] License Key Formatting
#

# @lc code=start
class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        s = s.upper().replace('-', '')
        n = len(s)
        res = s[0:(n % k)]
        for i in range(n // k):
            if res == '':
                res += s[n % k + i * k: n % k + (i + 1) * k]
            else:
                res += '-' + s[n % k + i * k: n % k + (i + 1) * k]
        return res
# @lc code=end

