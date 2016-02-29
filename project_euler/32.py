answer = 0
for num in range(100000):
    for x in range(2, int(num ** 0.5) + 1):
        check = [0] * 10
        if num % x == 0:
            a = x
            b = num / x
            c = num
            while a > 0:
                check[a % 10] += 1
                a /= 10
            while b > 0:
                check[b % 10] += 1
                b /= 10
            while c > 0:
                check[c % 10] += 1
                c /= 10

            if check == [0, 1, 1, 1, 1, 1, 1, 1, 1, 1]:
                print num
                answer += num
                break

print answer
