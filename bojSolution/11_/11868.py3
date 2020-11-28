import sys
input = sys.stdin.readline

input()
r=0
for c in [*map(int, input().split())]:
    r = r^c
print(["cubelover", "koosaga"][r!=0])