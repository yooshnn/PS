import sys
input = sys.stdin.readline

for _ in range(int(input())):
    input()
    s = list(map(int, input().split()))
    m, M = 1000001, -1000001
    for c in s:
        if c < m: m = c
        if c > M: M = c
    print(m, M)