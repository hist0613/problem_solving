class ObtainingDigitK:
	def minNumberToAdd(self, originalNumber, k):
		ans = 0
		while str(k) not in str(int(originalNumber) + ans):
			ans += 1
		return ans