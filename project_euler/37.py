def is_prime(x):
    if x == 1:
        return False
    for i in range(2, int(x ** 0.5) + 1):
        if x % i == 0:
            return False
    return True

if __name__ == "__main__":
    answers = []
    num = 10
    while len(answers) < 11:
        num += 1
        if is_prime(num) == False:
            continue
        flag = True
        
        temp_num = num
        while temp_num > 0:
            if is_prime(temp_num) == False:
                flag = False
                break
            temp_num /= 10

        temp_num = num
        while True:
            #print temp_num
            if is_prime(temp_num) == False:
                flag = False
                break
            if temp_num < 10:
                break
            temp_num = int(str(temp_num)[1:])

        if flag == True:
            answers.append(num)
            print num

    print sum(answers)
