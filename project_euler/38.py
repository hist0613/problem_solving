def is_9pandigital(x):
    return ''.join(sorted(x)) == '123456789'

max_pandigital = 0
for x in range(2, 10000):
    temp_str = ''
    i = 1
    while len(temp_str + str(x * i)) <= 9:
        temp_str += str(x * i)
        i += 1

    if is_9pandigital(temp_str) == True and int(temp_str) > max_pandigital:
        max_pandigital = int(temp_str)

print max_pandigital
