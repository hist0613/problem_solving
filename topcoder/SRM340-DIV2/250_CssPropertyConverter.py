class CssPropertyConverter:
	def getCamelized(self, cssPropertyName):
		return reduce(lambda x, y: x + y[0].upper() + y[1:], cssPropertyName.split('-'));