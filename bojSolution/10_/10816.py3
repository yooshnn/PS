from sys import stdin

N = stdin.readline()
A = stdin.readline().split()
M = stdin.readline()
B = stdin.readline().split()
d = {}
r = []

for n in A:
    try:
        d[n] += 1
    except:
        d[n] = 1
for i in B:
    try:
        r.append(d[i])
    except:
        r.append(0)
for i in r:
    print(i,end=" ")