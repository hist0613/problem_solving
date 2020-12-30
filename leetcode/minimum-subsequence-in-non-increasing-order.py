class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        ans = []
        nums = sorted(nums, reverse=True)
        total_sum = sum(nums)
        section_sum = 0
        for num in nums:
            section_sum += num 
            ans.append(num)
            if section_sum > total_sum - section_sum:
                break
        return ans