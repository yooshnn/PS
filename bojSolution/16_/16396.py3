import sys
input = sys.stdin.readline

dup = [0 for i in range(10000)]

for _ in range(int(input())):
    p, q = map(int, input().split())
    for i in range(p, q):
        dup[i-1] = 1
print(sum(dup))