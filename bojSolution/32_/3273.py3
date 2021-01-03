import sys; input = sys.stdin.readline

n = int(input())
s = sorted([*map(int, input().split())])
x = int(input())
res = 0

lp, rp = 0, n-1
while lp<rp:
    cur = s[lp]+s[rp]
    if cur==x: res += 1
    if cur<=x: lp += 1
    else: rp -= 1

print(res)
