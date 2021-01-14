import sys; input = sys.stdin.readline

N = int(input())
s = [set(input().split()[2:]) for _ in range(N)]
r = 0

for i in range(N-1):
    for j in range(i+1, N):
        r = max(r, len(s[i]&s[j]))

print(r+1)