class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        runsum = [0] * len(nums)
        runsum[0] = nums[0]
        for i in range(1, len(nums)):
            runsum[i] = runsum[i - 1] + nums[i]
        return runsum