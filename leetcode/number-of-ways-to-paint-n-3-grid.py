class Solution:
    def numOfWays(self, n: int) -> int:
        patterns = [
            "RYR", "YRY", "GRY",
            "RYG", "YRG", "GRG",
            "RGR", "YGR", "GYR",
            "RGY", "YGY", "GYG"
            ]

        def isSafe(a, b):
            for pic, pjc in zip(a, b):
                if pic == pjc:
                    return False
            return True

        nb_patterns = len(patterns)
        matched = [[] for _ in range(nb_patterns)]
        for pi in range(nb_patterns):
            for pj in range(nb_patterns):
                if pi == pj: continue
                if isSafe(patterns[pi], patterns[pj]):
                    matched[pi].append(pj)

        MOD = 1000000007
        pre = [1 for _ in range(nb_patterns)]
        for _ in range(n - 1):
            arr = [0 for _ in range(nb_patterns)]
            for pi in range(nb_patterns):
                for pj in matched[pi]:
                    arr[pi] += pre[pj]
                arr[pi] %= MOD
            pre = arr

        return sum(pre) % MOD