import bisect

class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        answer = []
        view = []
        for num in nums[::-1]:
            answer.insert(0, bisect.bisect_left(view, num))
            bisect.insort(view, num)
        return answer