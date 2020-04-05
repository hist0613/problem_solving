class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        ans = []
        
        A = A[::-1]
        A[0] = A[0] + K
        
        idx = 0
        while A[idx] >= 10:
            if idx + 1 < len(A):
                A[idx + 1] += A[idx] // 10
            else:
                A.append(A[idx] // 10)
            
            A[idx] %= 10
            idx += 1
            
        return A[::-1]