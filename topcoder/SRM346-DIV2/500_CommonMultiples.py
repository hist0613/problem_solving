import fractions
def lcm(a, b): return abs(a * b) / fractions.gcd(a, b) if a and b else 0

class CommonMultiples:
	def countCommMult(self, a, lower, upper):
		multiple = reduce(lambda x, y: lcm(x, y), a)
		return upper / multiple - (lower - 1) / multiple