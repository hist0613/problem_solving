class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        rightmost_max = -1
        for i in reversed(range(len(arr))):
            arr[i], rightmost_max = rightmost_max, max(arr[i], rightmost_max)
        return arr