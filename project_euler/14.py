ans = [1, 0]
for n in range(2, 1000001):
    t = n
    cnt = 0
    while t != 1:
        cnt += 1
        if t % 2 == 0:
            t /= 2
        else:
            t = 3 * t + 1
    if cnt > ans[1]:
        ans = [n, cnt]
        print ans
