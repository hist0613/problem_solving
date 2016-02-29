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

def wiggle_finder(arr, target):
    lp, rp = 0, 1
    total = arr[0] # sum(arr[lp:rp])
    while lp < rp and rp <= len(arr):
        if total == target:
            return rp - lp
        elif total < target:
            if rp < len(arr):
                total += arr[rp]
                rp += 1
            else:
                return -1
        else:
            total -= arr[lp]
            lp += 1
    return -1
    

if __name__ == '__main__':
    primes = filter(is_prime, [2] + range(3, 1000000, 2))
    answer = 0
    for prime in primes[-10000:]:
        cnt = wiggle_finder(primes, prime)
        if cnt > answer:
            answer = cnt
            print prime, answer
            
    print answer
