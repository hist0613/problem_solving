class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        evens = []
        odds = []
        for x in A:
            if x % 2:
                odds.append(x)
            else:
                evens.append(x)
        return evens + odds