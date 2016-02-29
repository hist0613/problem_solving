n = 5
cache = [0] * (n + 1)
cache[1] = 1
def how_many(x, maxd):
    if x <= 1:
        return 1
    if cache[x] != 0:
        return cache[x]
    else:
        ret = 0
        for i in range(1, maxd + 1):
            ret += how_many(x - i, i)
