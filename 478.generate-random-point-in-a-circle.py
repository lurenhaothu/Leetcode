#
# @lc app=leetcode id=478 lang=python3
#
# [478] Generate Random Point in a Circle
#

# @lc code=start
import random
class Solution:
    def __init__(self, radius: float, x_center: float, y_center: float):
        self.x = x_center
        self.y = y_center
        self.r = radius

    def randPoint(self) -> List[float]:
        res = [random.random() * 2 - 1, random.random() * 2 - 1]
        while res[0] ** 2 + res[1] ** 2 >= 1:
            res = [random.random() * 2 - 1, random.random() * 2 - 1]
        return [res[0] * self.r + self.x, res[1] * self.r + self.y]
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()
# @lc code=end

