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

def is_anagram(nums):
    nums = [sorted(str(num)) for num in nums]
    for num in nums:
        if num != nums[0]:
            return False
    return True
    

if __name__ == '__main__':
    primes = filter(is_prime, range(1001, 10000, 2))
    for i in range(len(primes)):
        for j in range(i + 1, len(primes)):
            p1 = primes[i]
            p2 = primes[j]
            p3 = primes[j] + (primes[j] - primes[i])
            if p3 in primes:
                if is_anagram([p1, p2, p3]):
                    print p1, p2, p3
                
