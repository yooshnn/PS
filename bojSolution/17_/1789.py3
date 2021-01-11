import sys; input = sys.stdin.readline

lp, rp = 1, 93000

X = int(input())
res = -1

while lp<=rp:
    mid = (lp+rp)//2
    s = (mid*(mid+1))//2
    if s<=X:
        res = max(res, mid)
        lp = mid+1
    else:
        rp = mid-1

print(res)
