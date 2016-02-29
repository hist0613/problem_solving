from math import factorial as f

def nCr(n, r):
    return f(n) / (f(r) * f(n - r))

if __name__ == '__main__':
    cnt = 0
    for i in range(1, 101):
        for j in range(1, i):
            if nCr(i, j) > 1000000:
                cnt += 1
                print i, j
    print cnt
                
