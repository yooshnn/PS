import sys
input = sys.stdin.readline

D = [0 for i in range(367)]
Q = [0 for i in range(367)]

for _ in range(int(input())):
    p, q = map(int, input().split())
    Q[p] += 1
    Q[q + 1] -= 1

cur = 0
for i in range(366):
    cur += Q[i]
    D[i] += cur

l = 0
M = 0
res = 0
for i in range(1, 366):
    if D[i]!=0:
        if D[i-1]==0:
            l = 0
            M=D[i]
        else:
            M=max(M, D[i])
        l += 1
    if i==365 or (D[i]==0 and D[i-1]!=0):
        res += l*M
        l = 0
        M = 0
print(res)