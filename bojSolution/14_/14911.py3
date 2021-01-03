import sys; input = sys.stdin.readline

s = [*map(int, input().split())]
t = int(input())
r = set()

for i in range(len(s)-1):
    for j in range(i+1, len(s)):
        if s[i]+s[j]==t:
            r.add((s[i], s[j]))
r = sorted(list(r))
for i in r:
    print(*i)
print(len(r))
