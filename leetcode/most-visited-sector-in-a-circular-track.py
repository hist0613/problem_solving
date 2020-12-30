class Solution:
    def mostVisited(self, n: int, rounds: List[int]) -> List[int]:
        counts = [0] * (n + 1)
        pos = rounds[0]
        counts[pos] = 1
        
        ridx = 1
        while ridx < len(rounds):
            pos += 1
            if pos > n:
                pos -= n
            counts[pos] += 1
            
            if pos == rounds[ridx]:
                ridx += 1
        
        max_count = max(counts)
        return [i for i in range(1, n + 1) if counts[i] == max_count]