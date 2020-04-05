class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        return sum([1 - len(str(num)) % 2 for num in nums])