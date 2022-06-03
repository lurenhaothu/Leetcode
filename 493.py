class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        n = len(nums)
        indexdic = nums.copy()
        indexdic.sort()
        newIndex = []
        dic = {}
        for i in indexdic:
            if not i in dic:
                newIndex.append(i)
                dic[i] = len(newIndex) - 1
        m = len(newIndex)
        seg = [0] * (2 * m)
        #print(dic)
        #print(newIndex)
        def getLargerIndex(i):
            if i >= newIndex[-1]:
                return -1
            start = 0
            end = m - 1
            while start < end:
                pivot = (start + end) // 2
                if newIndex[pivot] > i:
                    end = pivot
                else:
                    start = pivot + 1
            return start
        def getLargerSum(index):
            if index == -1:
                return 0
            i = index + m
            j = m - 1 + m
            res = 0
            while i <= j:
                if i % 2 == 1:
                    res += seg[i]
                    i += 1
                if j % 2 == 0:
                    res += seg[j]
                    j -= 1
                i = i // 2
                j = j // 2
            return res
        def update(i):
            index = dic[i]
            index += m
            while index >= 1:
                seg[index] += 1
                index  = index // 2
            return
        res = 0
        for i in range(n):
            index = getLargerIndex(nums[i] * 2)
            #print(index)
            res += getLargerSum(index)
            update(nums[i])
            #print(seg)
        return res