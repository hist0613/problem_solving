if __name__ == '__main__':
    for num in range(1, 1000000):
        flag = True
        for mul in [2, 3, 4, 5, 6]:
            if sorted(str(num)) != sorted(str(num * mul)):
                flag = False
                break
        if flag == True:
            print num
            print [num * mul for mul in [2, 3, 4, 5 , 6]]
                
