c = int(input())
s = []

for i in range(0,c):
    del s[:]
    s = input().split()[1:].copy()
    s = [int(z) for z in s]
    
    avg = sum(s)/len(s)
    temp = 0
    for g in s:
        if g > avg:
            temp += 1
    print(format(temp/(len(s)),".3%"))