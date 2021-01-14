import sys; input = sys.stdin.readline

N, C = map(int, input().split())
f = sorted([int(input()) for _ in range(N)])

lp, rp = 1, 1000000000
r = 0

while lp<=rp:
    mid = (lp+rp)//2
    if mid==0: break
    cnt = 0
    for i in f:
        cnt += i//mid

    if cnt>=C:
        lp = mid+1
        r = mid
    else: rp = mid-1

print(sum(f)-r*C)
