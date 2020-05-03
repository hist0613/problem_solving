class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        n_rows = len(matrix)
        n_cols = len(matrix[0])
        
        row_mins = [987654321 for _ in range(n_rows)]
        col_maxs = [0 for _ in range(n_cols)]
        
        for i in range(n_rows):
            for j in range(n_cols):
                row_mins[i] = min(matrix[i][j], row_mins[i])
                col_maxs[j] = max(matrix[i][j], col_maxs[j])
        
        ans = []
        for i in range(n_rows):
            for j in range(n_cols):
                if matrix[i][j] == row_mins[i] and matrix[i][j] == col_maxs[j]:
                    ans.append(matrix[i][j])
        
        return ans