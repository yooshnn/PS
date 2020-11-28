import sys
input = sys.stdin.readline

d = "0123456789"
def conv(num, base):
    q, r = divmod(num, base)
    n = d[r]
    return conv(q, base) + n if q else n

n = int(input())
res = []

for i in range(2, 11):
    t, cnt = conv(n,i), 0
    for j in range(1, len(t)):
        if t[j-1]!=t[j]: cnt += 1
    res.append([cnt, 100-i, i])

print(sorted(res)[0][2])