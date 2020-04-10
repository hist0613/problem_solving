from collections import defaultdict

class Solution:
    def findLucky(self, arr: List[int]) -> int:
        count = defaultdict(int)
        for num in arr:
            count[num] += 1
        
        for num in sorted(count.keys(), reverse=True):
            if num == count[num]:
                return num
        
        return -1