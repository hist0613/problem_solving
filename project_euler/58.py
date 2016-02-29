import Prime

if __name__ == '__main__':
    primes = set(Prime.primes)
    diags = [1]
    nom = 0
    denom = 1
    for i in range(1, 1000000):
        d = i * 2
        denom += 4
        for j in range(4):
            diags.append(diags[-1] + d)
        for num in diags[-4:]:
            if Prime.is_prime(num) == True:
                nom += 1
        #print nom, denom
        if float(nom) / float(denom) < 0.1:
            print d + 1
            break
