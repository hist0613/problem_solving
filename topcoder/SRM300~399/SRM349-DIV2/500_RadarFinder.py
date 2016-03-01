class RadarFinder:
	def possibleLocations(self, x1, y1, r1, x2, y2, r2):
		sqr_addr = (r1 + r2) ** 2
		sqr_subr = (r1 - r2) ** 2
		d = (x1 - x2) ** 2 + (y1 - y2) ** 2
		
		if d == 0 and r1 == r2: return -1
		if d > sqr_addr or d < sqr_subr: return 0
		if d == sqr_addr or d == sqr_subr: return 1
		if d < sqr_addr and d > sqr_subr: return 2