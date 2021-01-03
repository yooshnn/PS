import sys; input = sys.stdin.readline

a, d, k = map(int, input().split())

c = 1
while -1000000<=a<=1000000:
    if a==k:
        print(c)
        sys.exit(0)
    a += d
    c += 1
print("X")