from itertools import permutations

answers = []
for digits in permutations('0123456789'):
    if int(''.join(digits[1:4])) % 2 == 0 \
       and int(''.join(digits[2:5])) % 3 == 0 \
       and int(''.join(digits[3:6])) % 5 == 0 \
       and int(''.join(digits[4:7])) % 7 == 0 \
       and int(''.join(digits[5:8])) % 11 == 0 \
       and int(''.join(digits[6:9])) % 13 == 0 \
       and int(''.join(digits[7:10])) % 17== 0:
        print ''.join(digits)
        answers.append(int(''.join(digits)))

print sum(answers)
