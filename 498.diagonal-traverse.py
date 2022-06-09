#
# @lc app=leetcode id=498 lang=python3
#
# [498] Diagonal Traverse
#

# @lc code=start
class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        m = len(mat)
        n = len(mat[0])
        res = []
        i = 0
        j = 0
        d = 0
        while len(res) != m * n:
            res.append(mat[i][j])
            if d == 0:
                if i - 1 >= 0 and j + 1 < n:
                    i -= 1
                    j += 1
                else:
                    if j + 1 < n:
                        j += 1
                        d = 1
                    else:
                        i += 1
                        d = 1
            else:
                if i + 1 < m and j - 1 >= 0:
                    i += 1
                    j -= 1
                else:
                    if i + 1 < m:
                        i += 1
                        d = 0
                    else:
                        j += 1
                        d = 0
        return res
                
            
# @lc code=end

