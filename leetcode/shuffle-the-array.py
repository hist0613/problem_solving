import itertools

class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        return list(itertools.chain(*zip(nums[:n], nums[n:])))