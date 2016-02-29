import itertools
import Prime

primes = Prime.primes[:2000]

def is_right(five):
    for p1, p2 in itertools.permutations(five, 2):
        if Prime.is_prime(str(p1) + str(p2)) == False:
            return False
    return True

def make_chain(chain):
    if len(chain) == 5:
        return chain
    for p in primes:
        if p > chain[-1] and is_right(chain + [p]):
            new_chain = make_chain(chain + [p])
            if new_chain:
                return new_chain
    return False

if __name__ == '__main__':
    # use 'set intersection' way
    # with each prime, make chain of primes that can be prime even when concatenated.
    chain = 0
    while not chain:
        chain = make_chain([primes.pop(0)])
    print chain
