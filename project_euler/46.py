def is_prime(x):
    if x == 1:
        return False
    elif x == 2:
        return True
    elif x % 2 == 0:
        return False

    for i in range(3, int(x ** 0.5) + 1, 2):
        if x % i == 0:
            return False
        
    return True

primes = filter(is_prime, xrange(100000))
if __name__ == '__main__':
    for num in set(range(3, 100000, 2)) - set(primes):
        print num, 
        flag = False
        for prime in primes:
            if num - prime < 2:
                break
            temp = (num - prime) / 2
            if (temp ** 0.5).is_integer() == True:
                flag = True
                break
        if flag == True:
            print "is composite number"
        else:
            print "is not composite!!"
            break
        
        
