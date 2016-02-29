class Paintball:
	def getLeaderboard(self, players, messages):
		belongs = {}
		scores = {}
		for player in players:
			name, team = player.split()
			belongs[name] = team
			scores[name] = 0
		
		for message in messages:
			who, splattered, whom = message.split()
			if belongs[who] == belongs[whom]:
				scores[who] -= 1
			else:
				scores[who] += 1
				scores[whom] -= 1
		
		scores = sorted(scores.items(), key=lambda x:(-x[1], x[0]))
		
		team_scores = {}
		for whose, score in scores:
			team = belongs[whose]
			team_scores[team] = team_scores.get(team, 0) + score
		
		team_scores = sorted(team_scores.items(), key=lambda x:(-x[1], x[0]))
		
		ret = []
		for team, score in team_scores:
			ret.append(team + ' ' + str(score))
			for member, score in scores:
				if belongs[member] == team:
					ret.append('  ' + member + ' ' + str(score))
		
		return ret