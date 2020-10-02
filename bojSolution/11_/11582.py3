from sys import stdin
def input(): return stdin.readline().rstrip()

n = int(input())
s = list(map(int, input().split()))
k = int(input())

for i in range(k):
    print(*sorted(s[ n//k * i : n//k * (i + 1) ]), end=" ")