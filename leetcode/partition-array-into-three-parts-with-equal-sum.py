class Solution:
    def canTwoPartsEqualSum(self, arr: List[int]) -> bool:
        two_sum = sum(arr)
        seq_sum = 0
        for i in range(len(arr) - 1):
            seq_sum += arr[i]
            if seq_sum == two_sum // 2:
                return True
        return False
        
    
    def canThreePartsEqualSum(self, arr: List[int]) -> bool:
        three_sum = sum(arr)
        if three_sum % 3 != 0:
            return False
        
        seq_sum = 0
        result = False
        for i in range(len(arr) - 2):
            seq_sum += arr[i]
            if seq_sum == three_sum // 3:
                result = self.canTwoPartsEqualSum(arr[i + 1:])
            if result == True:
                break
            
        return result