from math import factorial

def next_number(num):
    ret = 0
    while num > 0:
        ret += factorial(num % 10)
        num /= 10
    return ret

if __name__ == '__main__':
    nexts = [0] + [next_number(n) for n in range(1, factorial(9) * 6 + 1)]

    answer = 0
    for num in xrange(1, 1000001):
        o = num
        cnt = 0
        check = set([num])
        while True:
            num = nexts[num]
            cnt += 1
            if num in check:
                break
            check.add(num)
            
        if cnt == 60:
            answer += 1
    print answer
