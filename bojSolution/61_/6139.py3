from sys import stdin
import math

N,K=map(int,stdin.readline().split())
for _ in range(K):
    s,t,r=map(int,stdin.readline().split())
    res=0
    cnt=0
    while True:
        if N-cnt<=s*t:
            res+=math.ceil((N-cnt)/s)
            break
        else:
            cnt+=s*t
            res+=t+r
    print(res)
