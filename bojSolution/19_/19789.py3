import sys
input = sys.stdin.readline

res = set()
n = int(input())

castle = [tuple(map(int, input().split())) for i in range(n)]

for i, (x, y) in enumerate(sorted(castle)):
    if i == 0:
        prev = x
        continue
    if x != prev: res.add(("x", x))
    else: res.add(("y", y))
    prev = x

print(len(res))
for r in sorted(res):
    print(*r)
