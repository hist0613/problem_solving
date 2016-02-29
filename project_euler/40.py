d = ' '
num = 1
while len(d) <= 1000000:
    d += str(num)
    num += 1
    
print reduce(lambda x, y: int(x) * int(y), [d[1], d[10], d[100], d[1000], d[10000], d[100000], d[1000000]])
