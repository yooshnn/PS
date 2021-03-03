import sys; input = sys.stdin.readline

N, M = map(int, input().split())
d = {}
res = []

for _ in range(N):
    s = input().rstrip()
    if len(s)>=M:
        try: d[s] += 1
        except: d[s] = 1

for key in d: res.append([-d[key], -len(key), key])
for i in sorted(res): print(i[2])