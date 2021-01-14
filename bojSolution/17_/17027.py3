import sys; input = sys.stdin.readline

N = int(input())
res = 0
query = []

for _ in range(N):
    query.append([*map(int, input().split())])

for CASE in range(1, N+1):
    s = [0 for _ in range(N+1)]
    s[CASE] = 1
    cnt = 0
    for q in query:
        s[q[0]] ^= s[q[1]]
        s[q[1]] ^= s[q[0]]
        s[q[0]] ^= s[q[1]]
        if s[q[2]]==1:
            cnt += 1
    res = max(res, cnt)

print(res)
