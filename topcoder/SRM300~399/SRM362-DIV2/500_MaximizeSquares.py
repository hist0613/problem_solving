class MaximizeSquares:
	def squareCount(self, N):
		ret = 0
		n = int(N ** 0.5)
		N -= n * n
		for i in range(1, n): ret += i * i
		if N >= n:
			N -= n
			for i in range(1, n): ret += i
		for i in range(1, N): ret += i
		return ret