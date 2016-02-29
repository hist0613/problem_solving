def dsum(x):
    res = 0
    for i in range(1, x / 2 + 1):
        if x % i == 0:
            res += i
    return res

ans = 0
for i in range(1, 10001):
    if i == dsum(dsum(i)) and i != dsum(i):
        print i, dsum(i), dsum(dsum(i))
        ans += i
print ans
