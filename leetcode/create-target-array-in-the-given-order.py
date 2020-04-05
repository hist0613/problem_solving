class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        ret = []
        for num, idx in zip(nums, index):
            ret.insert(idx, num)
        return ret