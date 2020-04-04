from collections import defaultdict

class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        count = defaultdict(int)
        
        for x in arr:
            count[x] += 1
            
        if count[0] >= 2:
            return True
        
        count.pop(0)
        for x in arr:
            if x * 2 in count:
                return True
        return False 