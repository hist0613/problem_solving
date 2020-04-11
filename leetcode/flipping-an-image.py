class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        A = [[1 - x for x in row[::-1]] for row in A]
        return A