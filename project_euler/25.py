f = [0, 1, 1]
idx = 3
while True:
    f.append(f[idx - 1] + f[idx - 2])
    if len(str(f[idx])) >= 1000:
        print idx
        break
    idx += 1
        
