class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        n = len(timeSeries)
        end = int(3e7)
        res = 0
        for i in range(n - 1, -1, -1):
            a = timeSeries[i]
            last = min(a + duration - 1, end)
            res += last - a + 1
            end = a - 1
        return res