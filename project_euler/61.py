P3 = [str(n * (n + 1) / 2) for n in range(1, 1000) if len(str(n * (n + 1) / 2)) == 4]
P4 = [str(n * n) for n in range(1, 1000) if len(str(n * n)) == 4]
P5 = [str(n * (3 * n - 1) / 2) for n in range(1, 1000) if len(str(n * (3 * n - 1) / 2)) == 4]
P6 = [str(n * (2 * n - 1)) for n in range(1, 1000) if len(str(n * (2 * n - 1))) == 4]
P7 = [str(n * (5 * n - 3) / 2) for n in range(1, 1000) if len(str(n * (5 * n - 3) / 2)) == 4]
P8 = [str(n * (3 * n - 2)) for n in range(1, 1000) if len(str(n * (3 * n - 2))) == 4]

Ps = [P3, P4, P5, P6, P7, P8, P3]

def is_chain(angle, num, ans):
    if sum(angle) == 6:
        if ans[0][:2] != ans[5][2:]:
            return False, None
        else:
            return True, ans
    for idx in range(6):
        if angle[idx] != 0:
            continue
        for x in Ps[idx]:
            if x[:2] == num[2:]:
                tangle = list(angle)
                tangle[idx] = 1
                result, answer = is_chain(tangle, x, ans + [x])
                if result == True:
                    print answer
    return False, None

if __name__ == '__main__':
    for num in P3:
        is_chain([1, 0, 0, 0, 0, 0], num, [num])
