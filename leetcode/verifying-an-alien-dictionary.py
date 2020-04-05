import string

class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        order = dict((c, o) for c, o in zip(order, string.ascii_lowercase))
        
        sequences = []
        for word in words:
            sequences.append(''.join([order[c] for c in word]))
        
        for i in range(len(sequences) - 1):
            if sequences[i] >= sequences[i + 1]:
                return False
            
        return True