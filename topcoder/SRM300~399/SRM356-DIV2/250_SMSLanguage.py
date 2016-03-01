class SMSLanguage:
	def translate(self, text):
		return text.replace('.', '').replace(',', '').replace('?', '').replace('!', '').lower().replace('and', '&').replace('ate', '8').replace('at', '@').replace('you', 'U')