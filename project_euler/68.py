from itertools import permutations

teams = [[0, 1, 3], [2, 3, 5], [4, 5, 7], [6, 7, 9], [8, 9, 1]]

def make_sequence(ms):
    ret = ''
    start = 0
    for i in range(5):
        if ms[teams[i][0]] < ms[teams[start][0]]:
            start = i
    for i in range(5):
        for idx in teams[(start + i) % 5]:
            ret += str(ms[idx])
    return int(ret)

if __name__ == '__main__':
    answer = 0
    for pack in permutations([1, 2, 3, 4, 5, 6, 7, 8, 9]):
        ms = [10] + list(pack)
        sums = [sum([ms[i] for i in team]) for team in teams]
        if all(x == sums[0] for x in sums) == True:
            answer = max(answer, make_sequence(ms))
    print answer
