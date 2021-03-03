import sys; input = sys.stdin.readline

n = int(input())
if n<3:
    print(0)
    sys.exit(0)

s = [*map(int, input().split())]

oneCnt = (s[0]==1)
dp = 0
res = 0

for i in range(1, n):
    if s[i]==1: oneCnt += 1
    if s[i]==2: dp = oneCnt + 2*dp
    if s[i]==3: res += dp
    dp %= int(1e9+7)
    res %= int(1e9+7)

print(res)