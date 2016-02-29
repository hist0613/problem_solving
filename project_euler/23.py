def dsum(x):
    res = 0
    for i in range(1, x / 2 + 1):
        if x % i == 0:
            res += i
    return res

over_num = []
for i in range(12, 28123):
    if dsum(i) > i:
        over_num.append(i)

print len(over_num)

check = set()
for i in range(len(over_num)):
    for j in range(i, len(over_num)):
        check.add(over_num[i] + over_num[j])

ans = 0
for i in range(28123):
    if i not in check:
        ans += i

print ans
        
        
