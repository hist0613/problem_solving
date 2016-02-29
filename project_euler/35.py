def is_prime(x):
    for i in range(2, int(x ** 0.5) + 1):
        if x % i == 0:
            return False
    return True
 
def circulate(x):
    ret = int(str(x)[1:] + str(x)[0])
    return ret
 
circular_primes = []
for num in range(2, 1000000):
    if is_prime(num):
        temp_num = num
        is_circular = True
        for i in range(len(str(num))):
            temp_num = circulate(temp_num)
            if len(str(temp_num)) != len(str(num)) or is_prime(temp_num) == False:
                is_circular = False
                break
        if is_circular == True:
            print num
            circular_primes.append(num)
 
print len(circular_primes)
