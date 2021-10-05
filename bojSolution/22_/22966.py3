import sys; input = sys.stdin.readline

n = int(input())
s = []

for i in range(n):
    x, y = input().split()
    s.append((int(y), x))

s.sort()
print(s[0][1])