import sys
input = sys.stdin.readline

d = {}
resName, res = "0", 0

for TEST in range(int(input())):
    n = input().rstrip()
    try:
        d[n] += 1
    except:
        d[n] = 1

    if d[n]>=res and resName<=n:
        res = d[n]
        resName = n

print(resName, res)
