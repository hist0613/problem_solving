class Solution:
    def numSteps(self, s: str) -> int:
        ans = 0
        x = int(s, 2)
        while x > 1:
            ans += 1
            x = x + 1 if x % 2 else x // 2
        return ans