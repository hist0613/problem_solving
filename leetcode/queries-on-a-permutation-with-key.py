class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        ans = []
        
        P = list(range(1, m + 1))
        for query in queries:
            idx = P.index(query)
            P = [query] + P[:idx] + P[idx+1:]
            ans.append(idx)
        
        return ans