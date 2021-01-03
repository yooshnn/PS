import sys; input=sys.stdin.readline

n = int(input())
s = [int(input()) for x in range(n)]
print(*sorted(s, reverse=True))