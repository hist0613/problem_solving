class Solution:
    def generateTheString(self, n: int) -> str:
        return "a" * (n - 1 + n % 2) + "b" * (1 - n % 2)