import sys; input = sys.stdin.readline

res = 1e9

for _ in range(int(input())):
    a, b = map(int, input().split())
    if a>b:
        print(0)
        sys.exit(0)
    res = min(res, b//a)

print(res)
