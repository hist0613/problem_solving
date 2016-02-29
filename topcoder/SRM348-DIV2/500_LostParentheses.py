class LostParentheses:
	def minResult(self, e):
		numbers = [int(x) for x in e.replace('+', ' +').replace('-', ' -').split()]
		
		for i, n in enumerate(numbers):
			if n < 0:
				return sum(numbers[:i]) - sum([abs(x) for x in numbers[i:]])
		else: return sum(numbers)