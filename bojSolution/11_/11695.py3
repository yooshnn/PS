import sys; input = sys.stdin.readline

n, m = map(int, input().split())
res = 0
for i in range(n):
    res ^= sum([*map(int, input().split())])

print("ainta" if res==0 else "august14")