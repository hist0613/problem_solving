dp = [[0] * 101 for i in range(50)]
class PillarsDivTwo:
	def maximalLength(self, height, w):
		n = len(height)
		for i in range(1, n):
			for j in range(1, height[i] + 1):
				for k in range(1, height[i - 1] + 1):
					dp[i][j] = max(dp[i][j],  dp[i - 1][k] + (w*w + (k-j)*(k-j))**0.5)
		return max(dp[n-1])