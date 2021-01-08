class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        dist = [987654321] * len(S)
        for i in range(len(S)):
            for j in range(len(S)):
                if S[j] == C and abs(j - i) < dist[i]:
                    dist[i] = abs(j - i)
        return dist