from collections import defaultdict
cubes = [''.join(sorted(str(x ** 3))) for x in range(1, 10001)]
counter = defaultdict(lambda:0)
for cube in cubes:
    counter[cube] += 1

for key, val in counter.iteritems():
    if val == 5:
        result = key

for cube in cubes:
    if cube == result:
        answer = (cubes.index(cube) + 1) ** 3

print result
print answer
