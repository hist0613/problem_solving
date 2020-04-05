class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        ans = []
        for freq, val in zip(nums[::2], nums[1::2]):
            ans.extend([val] * freq)
        return ans