class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        n = len(mat)
        m = len(mat[0])
        indices = [(ri, 0) for ri in range(n)] + [(0, ci) for ci in range(1, m)]
        for ri, ci in indices:
            seq = []
            x, y = ri, ci
            while x < n and y < m:
                seq.append(mat[x][y])
                x += 1; y += 1
            
            seq = sorted(seq)
            x, y = ri, ci
            sidx = 0
            while x < n and y < m:
                mat[x][y] = seq[sidx]
                x += 1; y += 1; sidx += 1
        return mat