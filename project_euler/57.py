from fractions import Fraction

if __name__ == '__main__':
    answer = 0
    a = Fraction(0)
    for i in range(1000):
        a = Fraction(1, 2 + a)
        r2 = Fraction(1) + a
        if len(str(r2.numerator)) > len(str(r2.denominator)):
            # print r2
            answer += 1
    print answer
        
        
    
