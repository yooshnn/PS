import sys; input = sys.stdin.readline

n, s = input().split()
q, r, res = [], "", 0
for i in range(int(n)):
    x, y = input().split()
    if x==s:
        r = y; break
    q.append(y)
for i in q:
    if i==r: res += 1
print(res)