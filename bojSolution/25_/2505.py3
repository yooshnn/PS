from sys import stdin
def input(): return stdin.readline().rstrip()

N = int(input())
O = list(map(int, input().split()))
flip = 0
res = []

s = [x for x in O]
for i in range(N):
    if flip == 2: break
    if s[i] != i+1:
        e = s.index(i+1)
        s[i:e+1] = s[i:e+1][::-1]
        flip += 1
        res.append((i+1,e+1))

if not all([x == i+1 for i, x in enumerate(s)]):
    flip = 0; res.clear()
    s = [x for x in O]
    for i in range(N-1,-1,-1):
        if flip == 2: break
        if s[i] != i+1:
            e = s.index(i+1)
            s[e:i+1] = s[e:i+1][::-1]
            flip += 1
            res.append((e+1,i+1))

for i in res: print(i[0],i[1])
for i in range(2-len(res)): print("1 1")