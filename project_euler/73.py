from fractions import gcd
import Prime

if __name__ == '__main__':
    answer = 0
    for d in range(2, 12001):
        for n in range(1, d):
            if gcd(d, n) == 1:
                if (1.0 / 3) < (float(n) / d) < (1.0 / 2):
                    answer += 1
    print answer
