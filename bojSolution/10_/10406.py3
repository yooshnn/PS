import sys
input = sys.stdin.readline

res = 0
a, b, c = map(int, input().split())
punch = [*map(int, input().split())]

for p in punch:
    res += (a<=p<=b)

print(res)