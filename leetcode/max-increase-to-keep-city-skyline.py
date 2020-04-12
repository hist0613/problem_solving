class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        n = len(grid)
        rowmax = [-1] * n
        colmax = [-1] * n
        for i in range(n):
            for j in range(n):
                rowmax[i] = max(grid[i][j], rowmax[i])
                colmax[j] = max(grid[i][j], colmax[j])
        
        ans = 0
        for i in range(n):
            for j in range(n):
                diff = min(rowmax[i], colmax[j]) - grid[i][j]
                ans += diff
                
        return ans