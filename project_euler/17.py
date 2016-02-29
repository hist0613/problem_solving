d2e_one = {0: '', 1:'one', 2:'two', 3:'three', 4:'four', 5:'five', 6:'six', 7:'seven', 8:'eight', 9:'nine'}
d2e_ten = {2:'twenty', 3:'thirty', 4:'forty', 5:'fifty', 6:'sixty', 7:'seventy', 8:'eighty', 9:'ninety'}
d2e_lt20 = {0: '', 1:'one', 2:'two', 3:'three', 4:'four', 5:'five', 6:'six', 7:'seven', 8:'eight', 9:'nine',
            10:'ten', 11:'eleven', 12:'twelve', 13:'thirteen', 14:'fourteen', 15:'fifteen', 16:'sixteen', 17:'seventeen', 18:'eighteen', 19:'nineteen'}
# 1 <= x <= 1000
def to_english(x):
        if x == 1000:
                return 'onethousand'
        
        s = ''
        if x >= 100:
                s += d2e_one[x / 100] + 'hundred'
                x %= 100
                if x != 0: s += 'and'

        if x >= 20:
                s += d2e_ten[x / 10]
                s += d2e_one[x % 10]
        else:
                s += d2e_lt20[x]

        return s

ans = 0
for i in range(1, 1001):
        #print to_english(i)
        ans += len(to_english(i))

print ans
