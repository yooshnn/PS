import sys; input = sys.stdin.readline

a, b = int(input()), int(input())
c, d = 1, 0
for i in range(b-1):
    print(c)
    d += c
    c += 1
print(a-d)
