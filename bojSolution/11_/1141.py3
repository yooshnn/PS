import sys
input = sys.stdin.readline

n = int(input())
res = n
s = [input().rstrip() for i in range(n)]
s.sort()

for i in range(n-1):
    if len(s[i])>len(s[i+1]): continue
    f = False
    for j in range(len(s[i])):
        if s[i][j]!=s[i+1][j]: f = True
    if f: continue
    res -= 1

print(res)