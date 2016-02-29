def digits_sum(num):
    return sum([int(digit) for digit in str(num)])

if __name__ == '__main__':
    answer = 0
    for a in xrange(1, 100):
        for b in xrange(1, 100):
            ds = digits_sum(a ** b)
            answer = max(ds, answer)
    print answer
