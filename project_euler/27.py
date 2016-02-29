def get_primes_lte(n):
    primes = []
    for i in range(2, n):
        flag = True
        for j in range(2, int(i ** 0.5) + 1):
            if i % j == 0:
                flag = False
                break
        if flag == True:
            primes.append(i)
            
    return primes

def is_prime(x):
    for i in range(2, int(x ** 0.5) + 1):
        if x % i == 0:
            return False
    return True

if __name__ == "__main__":
    n = 1000
    primes = get_primes_lte(n)
    b_candidates = primes + [-x for x in primes]
    
    max_cnt = 0
    answer = 0
    for b in b_candidates:
        for a in range(-n + 1, n):
            cnt = 0
            x = 0
            while True:
                result = x * x + a * x + b
                if result >= 0 and is_prime(result) == True:
                   cnt += 1
                else:
                    break
                x += 1
                
            if cnt > max_cnt:
                max_cnt = cnt
                answer = a * b
    print answer
