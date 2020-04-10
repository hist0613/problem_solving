class Solution:
    def smallestRepunitDivByK(self, K: int) -> int:
        if K % 2 == 0:
            return -1
        
        ans = 0
        n = 0
        for i in range(K):
            n = (n * 10 + 1) % K
            ans += 1
            if n == 0:
                return ans
            
        return -1