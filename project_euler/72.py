import Prime

def phi(num):
    ret = float(num)
    for prime in Prime.primes:
        if prime >= num:
            break
        if num % prime == 0:
            ret *= (1 - (1.0 / prime))
    return int(ret)

if __name__ == '__main__':
    n = input()
    if n in Prime.primes:
        print n - 1
    else:
        print phi(n)

'''
if __name__ == '__main__':
    answer = 0
    for num in xrange(2, 1000001):
        if num in Prime.primes:
            answer += num - 1
        else:
            answer += phi(num)
    print answer
'''
