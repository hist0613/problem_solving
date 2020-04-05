class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        answer = len(arr1)
        for num1 in arr1:
            for num2 in arr2:
                if abs(num1 - num2) <= d:
                    answer -= 1
                    break
        return answer