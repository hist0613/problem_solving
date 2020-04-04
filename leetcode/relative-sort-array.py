from collections import defaultdict

class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        count = defaultdict(int)
        for num in arr1:
            count[num] += 1
        
        ret = []
        for num in arr2:
            for _ in range(count[num]):
                ret.append(num)
            count.pop(num)
                    
        for num in sorted(count.keys()):
            for _ in range(count[num]):
                ret.append(num)
                
        return ret 
