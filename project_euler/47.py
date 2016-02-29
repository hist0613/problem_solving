def get_prime_factors(num):
    original = num
    factors = set()
    while num % 2 == 0:
        num /= 2
        factors.add(2)
    for i in range(3, int(original ** 0.5) + 1, 2):
        while num % i == 0:
            num /= i
            factors.add(i)
    if num != 1:
        factors.add(num)
    return factors

def is_all_different(factors, n):
    for factor in factors:
        if len(factor) != n:
            return False
    for factor in factors[1:]:
        if factors[0] == factor:
            print factors[0], factor
            return False
    return True
        
if __name__ == '__main__':
    n = 4
    for num in xrange(2, 1000000):
        nums = range(num, num+n)
        factors = [get_prime_factors(num) for num in nums]
        if is_all_different(factors, n):
            print nums
            break
