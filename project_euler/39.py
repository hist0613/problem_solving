max_cnt = 0
max_p = 0
for p in range(3, 1001):
    cnt = 0
    for a in range(1, p):
        for b in range(a, p):
            c = p - (a + b)
            if c >= a and c >= b and c < a + b and c ** 2 == a ** 2 + b ** 2:
                cnt += 1
    if cnt > max_cnt:
        max_cnt = cnt
        max_p = p

print max_cnt, max_p
