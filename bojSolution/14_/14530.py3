import sys; input = sys.stdin.readline

x, y = map(int, input().split())
p = x
res = 0

if x==y:
    print(0)
    sys.exit(0)

i, j = 1, 0
while 1:
    if j==0:
        res += abs(x+i-p)
        pp = p
        p = x+i
        if pp<=y and x+i>=y: break
    else:
        res += abs(p-(x-i))
        pp = p
        p = x-i
        if pp>=y and x-i<=y: break

    j = 1-j
    i *= 2

res -= abs(p-y)

print(res)
