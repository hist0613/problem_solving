import bisect

class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        positions = []
        
        for i in range(len(S)):
            if S[i] == C:
                positions.append(i)
        
        dist = [0] * len(S)
        for i in range(len(S)):
            pos = bisect.bisect_left(positions, i)
            ldist, rdist = 987654321, 987654321
            if pos > 0: ldist = abs(i - positions[pos - 1])
            if pos < len(positions): rdist = abs(i - positions[pos])
            dist[i] = min(ldist, rdist)
            
        return dist