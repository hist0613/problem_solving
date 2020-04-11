class Solution:
    def isSelfDividingNumber(self, number):
        digits = set()
        
        temp = number
        while temp > 0:
            digits.add(temp % 10)
            temp //= 10
        
        if 0 in digits:
            return False
        
        for digit in digits:
            if number % digit:
                return False
        return True
    
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        ans = []
        for x in range(left, right + 1):
            if self.isSelfDividingNumber(x):
                ans.append(x)
        return ans