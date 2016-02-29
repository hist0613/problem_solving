def get_last10_of_square(x):
    sq = 1
    for i in xrange(x):
        sq *= x
        sq %= 10000000000
    return sq

if __name__ == '__main__':
    num = 0
    for i in range(1, 1001):
        num += get_last10_of_square(i)
        num %= 10000000000
    print num
