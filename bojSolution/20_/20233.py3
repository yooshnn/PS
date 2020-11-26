import sys
input = sys.stdin.readline

a, x, b, y, T = int(input()), int(input()), int(input()), int(input()), int(input())
print(a + max(0, 21*(T-30)*x), b + max(0, 21*(T-45)*y))