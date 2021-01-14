import sys; input = sys.stdin.readline

a, b, c = sorted([*map(int, input().split())])

while c>=a+b:
    c -= 1

print(a+b+c)
