class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        start = 1
        end = area
        while start < end:
            pivot = (start + end + 1) // 2
            if pivot ** 2 > area:
                end = pivot - 1
            else:
                start = pivot
        for i in range(start, 0, -1):
            if area % i == 0:
                return [area // i, i]