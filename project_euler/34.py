from math import factorial as f

amazings = []
for num in range(3, 1000000):
    temp_num = num
    result = 0
    while temp_num > 0:
        result += f(temp_num % 10)
        temp_num /= 10
    if result == num:
        print num
        amazings.append(num)

print sum(amazings)
        
    
