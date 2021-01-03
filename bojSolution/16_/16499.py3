import sys; input = sys.stdin.readline

s = set()
n = int(input())
for _ in range(n):
    t = str(sorted(input()))
    s.add(t)

print(len(s))
