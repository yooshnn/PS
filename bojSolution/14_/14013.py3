import sys; input = sys.stdin.readline

x, y = map(float, input().split())
for TEST in range(int(input())):
    a, b = input().split(); a = float(a)
    if b=="A":
        print(y*a/x)
    else:
        print(x*a/y)
