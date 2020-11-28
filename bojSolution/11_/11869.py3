import sys
input = sys.stdin.readline

n = int(input())
s = [*map(int, input().split())]
r = 0

for c in s:
    r ^= c

print(["cubelover", "koosaga"][r!=0])