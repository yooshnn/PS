import sys
input = sys.stdin.readline

n = int(input())
res = 0
for a in range(1, 1001):
    for b in range(1, 1001):
        if a*a == b*b+n:
            res += 1
print(res)