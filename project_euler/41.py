def is_prime(x):
    if x == 1:
        return False
    for i in range(2, int(x ** 0.5) + 1):
        if x % i == 0:
            return False
    return True

def is_pandigital(x):
    return ''.join(sorted(str(x))) == '123456789'[:len(str(x))]
    

for num in xrange(7654321, 1000001, -2):
    if is_pandigital(num) == True:
        print num
        if is_prime(num) == True:
            print num
            break 
