import Prime

# reference : http://www.mathblog.dk/project-euler-69-find-the-value-of-n-%E2%89%A4-1000000-for-which-n%CF%86n-is-a-maximum/
if __name__ == '__main__':
    result = 1
    for prime in Prime.primes:
        if result * prime < 1000000:
            result *= prime
        else:
            break
    print result
    
"""
from fractions import gcd
import Prime

def ppi(n):
    ret = 1.0
    for prime in Prime.primes:
        if prime > n:
            break
        if n % prime == 0:
            ret *= (1 - (1.0 / prime))
    return ret
        
if __name__ == '__main__':
    answer_n = 6
    answer = 3
    for n in xrange(11, 1000000):
        val = 1.0 / ppi(n)
        if val > answer:
            answer_n = n
            answer = val
            print n, val

    print answer_n, answer
"""
