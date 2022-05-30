#
# @lc app=leetcode id=468 lang=python3
#
# [468] Validate IP Address
#

# @lc code=start
class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        if queryIP.count('.') == 3:
            numList = queryIP.split('.')
            for num in numList:
                try:
                    n = int(num)
                    if n > 0 and n <= 255 and num[0] != '0':
                        continue
                    elif n == 0 and len(num) == 1:
                        continue
                    else:
                        return "Neither"
                except ValueError:
                    return "Neither"
            return "IPv4"
        elif queryIP.count(':') == 7:
            numList = queryIP.split(':')
            for num in numList:
                if len(num) == 0 or len(num) > 4:
                    return "Neither"
                for c in num:
                    if not self.inRange(c):
                        return "Neither"
            return "IPv6"
                
        else:
            return "Neither"
    def inRange(self, c):
        if ord(c) >= ord('0') and ord(c) <= ord('9'):
            return True
        elif ord(c) >= ord('A') and ord(c) <= ord('F'):
            return True
        elif ord(c) >= ord('a') and ord(c) <= ord('f'):
            return True
        else:
            return False
# @lc code=end

