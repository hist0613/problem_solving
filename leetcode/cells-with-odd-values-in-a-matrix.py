import numpy as np

class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        arr = np.zeros((n, m), dtype='int32')
        for r_i, c_i in indices:
            arr[r_i, :] += 1
            arr[:, c_i] += 1
        
        ans = np.sum(arr % 2 == 1)
        return ans