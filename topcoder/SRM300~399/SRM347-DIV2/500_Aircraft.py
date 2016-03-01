class Aircraft:
	def nearMiss(self, p1, v1, p2, v2, R):
		# change (p1, p2) into (O, p1 - p2)
		Px, Py, Pz = p1[0] - p2[0], p1[1] - p2[1], p1[2] - p2[2]
		Vx, Vy, Vz = v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]
		
		# (P + t * V)^2 <= R^2
		# At^2 + Bt + C <= 0
		A = Vx * Vx + Vy * Vy + Vz * Vz
		B = 2 * (Px * Vx + Py * Vy + Pz * Vz)
		C = Px * Px + Py * Py + Pz * Pz - R * R
		
		if C <= 0: return "YES" # at t = 0, "near miss"
		elif A == 0: return "NO" # V = 0 -> P1 != P2 and V1 == V2
		elif B >= 0: return "NO" # x-coordinate of graph's vertex <= 0
		elif B * B - 4 * A * C >= 0: return "YES" # graph meet x-axis ( means graph <= 0 )
		else: return "NO"