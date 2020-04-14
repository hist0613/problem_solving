class Solution:
    def hasSuperString(self, target, words):
        for word in words:
            if target in word and target != word:
                return True
        return False
            
    def stringMatching(self, words: List[str]) -> List[str]:
        ans = []
        for word in words:
            if self.hasSuperString(word, words):
                ans.append(word)
        return ans