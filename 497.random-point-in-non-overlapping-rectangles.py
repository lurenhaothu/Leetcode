#
# @lc app=leetcode id=497 lang=python3
#
# [497] Random Point in Non-overlapping Rectangles
#

# @lc code=start
class Solution:

    def __init__(self, rects: List[List[int]]):
        self.rects = rects
        self.n = len(rects)
        self.s = [(rects[i][3] - rects[i][1] + 1) * (rects[i][2] - rects[i][0] + 1) for i in range(self.n)]
        #self.s = [1 for i in range(self.n)]
        self.prefix = [self.s[0]] * self.n
        for i in range(1, self.n):
            self.prefix[i] = self.prefix[i - 1] + self.s[i]
        #print(self.prefix)

    def pick(self) -> List[int]:
        i = self.getIndex()
        a = int(random.random() * (self.rects[i][2] - self.rects[i][0] + 1)) + self.rects[i][0]
        b = int(random.random() * (self.rects[i][3] - self.rects[i][1] + 1)) + self.rects[i][1]
        return [int(a), int(b)]
    def getIndex(self):
        index = random.random() * self.prefix[-1]
        start = 0
        end = self.n - 1
        while start < end:
            pivot = (start + end) // 2
            if self.prefix[pivot] <= index:
                start = pivot + 1
            else:
                end = pivot
        return start

# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()
# @lc code=end

