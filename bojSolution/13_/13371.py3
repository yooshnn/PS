import sys
input = sys.stdin.readline

for TEST in range(int(input())):
    n = int(input()); n-= 1
    lp, rp = 0, 36515
    mid = (lp+rp)//2
    s1 = s2 = 0
    while lp<=rp:
        mid = (lp+rp)//2
        s1 = mid*(6+(mid-1)*3)//2
        s2 = (mid+1)*(6+mid*3)//2
        if s1<=n<s2:
            break
        elif s2<=n:
            lp = mid+1
        else:
            rp = mid-1
    req = (n-s1)//((s2-s1)//3)
    if req==0: print("%d dolphin%s"%(mid+1, "" if mid+1==1 else "s"))
    elif req==1: print("%d jump%s"%(mid+1, "" if mid+1==1 else "s"))
    else: print("splash")