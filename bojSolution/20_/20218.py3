import sys
input = sys.stdin.readline

M, res = -99999, ""
suspicious = True
d = {}

N = int(input())
for RANK in range(N):
    d[input().rstrip()] = RANK
for RANK in range(N):
    d[input().rstrip()] -= RANK

for keys in d:
    diff = d[keys]
    if diff != 0: suspicious = False
    if diff>M:
        M = diff
        res = keys

if suspicious: print("suspicious")
else: print(res)