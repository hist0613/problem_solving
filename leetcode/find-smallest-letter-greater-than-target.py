class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        exists = [0] * 26
        for letter in letters:
            exists[ord(letter) - ord('a')] = 1
        
        for i in range(ord(target) - ord('a') + 1, ord(target) - ord('a') + 26):
            if exists[i % 26] == 1:
                return chr(ord('a') + (i % 26))