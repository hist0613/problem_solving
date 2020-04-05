class Solution:
    def permute(self, texts, c):
        if c.isdigit():
            return [text + c for text in texts]
        else:
            return [text + c.lower() for text in texts] + \
                   [text + c.upper() for text in texts]
    
    def letterCasePermutation(self, S: str) -> List[str]:
        answer = [""]
        for c in S:
            answer = self.permute(answer, c)
        return answer