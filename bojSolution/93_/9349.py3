import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, k = map(int, input().split())
    res = 0
    for i in range(1, n):
        if (i+1)*(k-1)+1 <= n: res = i
    print(res)