class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        tokens = text.split()
        
        thirds = []
        for a, b, c in zip(tokens[0:], tokens[1:], tokens[2:]):
            if a == first and b == second:
                thirds.append(c)
        
        return thirds