class DiamondHunt:
	def countDiamonds(self, mine):
		cnt = 0
		while "<>" in mine:
			cnt += 1
			mine = mine.replace("<>", "", 1)
		return cnt