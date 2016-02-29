class HandsShaking:
	def countPerfect(self, n):
		ans = [0] * 31
		ans[0] = ans[1] = 1
		ans[2] = 2
		for i in range(3, n / 2 + 1):
			for j in range(i):
				ans[i] += ans[j] * ans[i - j - 1]
		return ans[n / 2]