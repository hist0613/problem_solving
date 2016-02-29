if __name__ == '__main__':
    cnt = 0
    for n in range(1, 101):
        for d in range(1, 101):
            if len(str(d ** n)) == n:
                print d, n, d ** n
                cnt += 1
    print cnt
