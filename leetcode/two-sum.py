class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num2idx = {}
        for idx, num in enumerate(nums):
            num2idx[num] = idx
            
        for i in range(len(nums)):
            if target - nums[i] in num2idx and num2idx[target - nums[i]] != i:
                return [i, num2idx[target-nums[i]]]
