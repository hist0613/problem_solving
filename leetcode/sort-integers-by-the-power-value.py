from collections import defaultdict

class Solution:
    def __init__(self):
        self.powers = defaultdict(int)
        self.powers[1] = 0
    
    def getPower(self, num):
        if num not in self.powers:
            if num % 2 == 0:
                self.powers[num] = self.getPower(num // 2) + 1
            else:
                self.powers[num] = self.getPower(3 * num + 1) + 1
        return self.powers[num]
    
    def getKth(self, lo: int, hi: int, k: int) -> int:
        pairs = [(self.getPower(num), num) for num in range(lo, hi + 1)]
        pairs = sorted(pairs)
        return pairs[k - 1][1]