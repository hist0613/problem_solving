class Solution:
    def sumZero(self, n: int) -> List[int]:
        ans = [x for x in range(1 - n % 2, n // 2 + 1)]
        ans = ans + [-x for x in range(1, n // 2 + 1)]
        return ans