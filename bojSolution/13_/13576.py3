from sys import stdin
from bisect import bisect_left
input = stdin.readline

res = 1
Z, sfx = [], []

def getZ(s):
    global res, Z
    l, r, L = 0, 0, len(s)
    Z = [0 for x in range(L)]; Z[0] = L; sfx.append(Z[0])
    for i in range(1,L):
        if i>r:
            l=r = i
            while r<L and s[r]==s[r-l]: r+=1
            Z[i] = r-l
            r -= 1
        else:
            if Z[i-l]<=r-i:
                Z[i] = Z[i-l]
            else:
                l = i
                while r<L and s[r]==s[r-l]: r+=1
                Z[i] = r-l
                r -= 1
        if Z[i] != 0: sfx.append(Z[i])
        if Z[i] + i == L: res += 1

s = input().rstrip()
getZ(s); sfx = sorted(sfx)

print(res)
for i in range(len(s)-1, -1, -1):
    if Z[i] + i != len(s): continue
    print(Z[i], len(sfx) - bisect_left(sfx, Z[i]))