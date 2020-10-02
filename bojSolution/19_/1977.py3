from sys import stdin

m = int(stdin.readline())
n = int(stdin.readline())

s = 0
t = -1

for i in range(1,101):
    if i*i >= m and i*i <= n:
        if t == -1:
            t = i*i
        s += i*i

if t == -1:
    print(-1)
else:
    print(s)
    print(t)