from sys import stdin
from math import gcd
ans = []
t = int(stdin.readline())
for i in range(t):
    a,b = map(int,stdin.readline().split())
    temp = [a]
    temp.append(b)
    ans.append(temp)
for i in range(t):
    print(int(ans[i][0]*ans[i][1]/gcd(ans[i][0],ans[i][1])))