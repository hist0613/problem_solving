from fractions import gcd

if __name__ == '__main__':
    answer = 2.0 / 5
    answer_n = 2
    answer_d = 5
    for d in range(8, 1000001):
        n = int(float(d) * 3.0 / 7.0)
        while gcd(d, n) != 1 and n > 1:
            n -= 1
        if n <= 0:
            continue
        if float(n) / d > answer:
            answer = float(n) / d
            answer_n = n
            answer_d = d
    print answer
    print answer_n, answer_d
