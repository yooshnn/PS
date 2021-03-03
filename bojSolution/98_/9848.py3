import sys; input = sys.stdin.readline

res = 0
N, K = map(int, input().split())

t = int(input())
for i in range(N-1):
    c = int(input())
    if c+K<=t: res += 1
    t = c

print(res)