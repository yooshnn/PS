import sys; input = sys.stdin.readline

s = sorted([*map(int, input().split())])
print(*s[:2], max(s)-sum(s[:2]))