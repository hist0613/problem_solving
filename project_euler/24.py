import itertools

dic = ['2', '0', '1', '3', '4', '5', '6', '7', '8', '9']
idx = 0
for per in itertools.permutations(dic):
    idx += 1
    if idx == 274240:
        print ''.join(per)
