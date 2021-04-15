import sys; input = sys.stdin.readline

n = int(input())
s = [int(input()) for i in range(n)]
r = 2e16

for i in range(n-1):
    for j in range(n):
        t = 0
        for k in s:
            if abs(k-s[i]) < abs(k-s[j]): t += (k-s[i])**2
            else: t += (k-s[j])**2
        r = min(r, t)

print(r)
