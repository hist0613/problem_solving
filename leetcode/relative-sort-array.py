class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        count = [0] * 1001
        for num in arr1:
            count[num] += 1
        
        ret = []
        for num in arr2:
            for _ in range(count[num]):
                ret.append(num)
            count[num] = 0
                    
        for num in range(1001):
            for _ in range(count[num]):
                ret.append(num)
                
        return ret 
