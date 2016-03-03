a_walk = 1
diag_walk = 0.5 ** 0.5 
moves = {
	"NORTH": (0, a_walk),
	"SOUTH": (0, -a_walk),
	"EAST": (a_walk, 0),
	"WEST": (-a_walk, 0),
	"NORTHEAST": (diag_walk, diag_walk),
	"NORTHWEST": (-diag_walk, diag_walk),
	"SOUTHEAST": (diag_walk, -diag_walk),
	"SOUTHWEST": (-diag_walk, -diag_walk)
}

class PirateTreasure:
	def getDistance(self, steps, directions):
		n = len(steps)
		x = 0
		y = 0
		for i in range(n):
			x += (moves[directions[i]][0] * steps[i])
			y += (moves[directions[i]][1] * steps[i])
		return (x ** 2 + y ** 2) ** 0.5