class MirroredClock:
	def whatTimeIsIt(self, time):
		mm = (60 - int(time[3:])) % 60
		hh = (12 - int(mm>0) - int(time[:2])) % 12
		return "%02d:%02d" % (hh, mm)