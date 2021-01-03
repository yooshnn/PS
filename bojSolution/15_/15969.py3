import sys; input=sys.stdin.readline

n = int(input())
s = [*map(int, input().split())]
print(max(s)-min(s))
