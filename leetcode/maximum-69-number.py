class Solution:
    def maximum69Number (self, num: int) -> int:
        num = str(num)
        if '6' not in num:
            return int(num)
        num = num[:num.index('6')] + '9' + num[num.index('6')+1:]
        return int(num)