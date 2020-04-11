class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        check = set()
        for x in A:
            if x in check:
                return x
            check.add(x)