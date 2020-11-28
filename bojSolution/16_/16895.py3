import sys
input = sys.stdin.readline

r = 0
res = 0
n = int(input())
s = [*map(int, input().split())]
for c in s:
    r ^= c

if r==0:
    print(0)
else:
    for i in range(n):
        t = 0
        for j in range(n):
            if i==j:
                continue
            t ^= s[j]
        for k in range(s[i]-1):
            if k^t==0:
                res += 1
    print(res)
