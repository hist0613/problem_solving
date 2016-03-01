class MorselikeCode:
	def decrypt(self, library, message):
		codes = dict([(code[2:], code[:1]) for code in library])
		return ''.join([codes.get(sequence, '?') for sequence in message.split()])