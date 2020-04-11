class Solution:
    def freqAlphabets(self, s: str) -> str:
        int2alpha = {str(x): chr(x - 1 + ord('a')) for x in range(1, 27)}
        
        ans = ""
        substr = ""
        for c in s:
            if c == '#':
                for c_ in substr[:-2]:
                    ans += int2alpha[c_]
                ans += int2alpha[substr[-2:]]
                substr = ""
            else:
                substr += c
            
        for c in substr:
            ans += int2alpha[c]
            
        return ans