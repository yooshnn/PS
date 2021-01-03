import sys; input=sys.stdin.readline

n = int(input())
s = [int(input()) for x in range(n)]
s.sort()
n = min(n, 5)
t = s[:n]

r = []
for i in range(n-1):
    for j in range(i+1, n):
        r.append(int(str(t[i])+str(t[j])))
        r.append(int(str(t[j])+str(t[i])))
print(sorted(r)[2])
