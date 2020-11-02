import sys
input = sys.stdin.readline

n, k = map(int, input().split())
s = [*map(int, input().split())]
streak, res = 0, 1

for i, c in enumerate(s):
    if i==0:
        streak += 1
        continue
    if s[i-1]==c: streak = 1
    else: streak += 1
    res = max(res, streak)

print(res)