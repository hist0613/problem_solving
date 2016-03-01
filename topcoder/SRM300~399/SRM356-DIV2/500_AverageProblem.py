class AverageProblem:
	def numberOfParticipants(self, _marks):
		_marks = ' '.join(_marks)
		marks = []
		for m in _marks.split():
			n, d = [int(x) for x in m.split('.')]
			marks.append(n * 1000 + d)
		
		for p in range(1, 1001):
			flag = True
			for m in marks:
				n = ((m + 1) * p - 1) / 1000
				if m * p > n * 1000:
					flag = False
					break
					
			if flag == True:
				return p
				
		return 1000