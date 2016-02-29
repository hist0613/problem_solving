from fractions import Fraction

funny = []
for b in range(10, 100):
    for a in range(10, b):
        original = Fraction(a, b)
        diffs = []
        if b % 10 > 0:
            if a % 10 == b / 10: diffs.append(Fraction(a / 10, b % 10))
            if a / 10 == b / 10: diffs.append(Fraction(a % 10, b % 10))
        if a / 10 == b % 10: diffs.append(Fraction(a % 10, b / 10))

        for diff in diffs:
            if original == diff:
                funny.append(original)

answer = reduce(lambda x, y: x * y, funny)
print answer
                
        
