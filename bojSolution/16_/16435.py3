import sys; input = sys.stdin.readline

N, L = map(int, input().split())
s = sorted([*map(int, input().split())])

for c in s:
    if c<=L:
        L += 1

print(L)