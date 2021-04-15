n = int(input())
res = 0
for i, c in enumerate([*map(int, input().split())]):
    res += min(7, c) - (3 if i&1 else 2)
print(res)