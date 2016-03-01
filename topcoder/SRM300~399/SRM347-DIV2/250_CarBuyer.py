class CarBuyer:
	def lowestCost(self, cars, fuelPrice, annualDistance, years):
		def cost(car):
			[purchase_cost, tax, fuel_efficiency] = [float(val) for val in car.split()]
			return purchase_cost + tax * years + fuelPrice * annualDistance * years / fuel_efficiency
		return min([cost(car) for car in cars])