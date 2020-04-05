from collections import defaultdict

class Solution:
    def sortString(self, s: str) -> str:
        alpha = defaultdict(int)
        for c in s:
            alpha[c] += 1
        
        prev_ans = ""
        ans = ""
        while True:
            for c in sorted(alpha.keys()):
                ans += c
                alpha[c] -= 1
                if alpha[c] == 0: alpha.pop(c)
            
            for c in reversed(sorted(alpha.keys())):
                ans += c
                alpha[c] -= 1
                if alpha[c] == 0: alpha.pop(c)
            
            if prev_ans == ans:
                break
                
            prev_ans = ans
        
        return ans