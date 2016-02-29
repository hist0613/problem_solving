def is_pentangular(x):
    return (((6 * x + 0.25) ** 0.5 + 0.5) / 3).is_integer()

def get_pentangular(n):
    return n * (3 * n - 1) / 2

P = [get_pentangular(x) for x in xrange(1, 100001)]

min_d = 987654321
for j in xrange(1, 100001):
    for k in xrange(j + 1, 100001):
        Pj = P[j]
        Pk = P[k]
        if Pk - Pj > min_d:
            break
        if is_pentangular(Pj + Pk) == True and is_pentangular(Pk - Pj) == True:
            min_d = min(Pk - Pj, min_d)
            print min_d
            
print min_d
