import sys
input = sys.stdin.readline

t, p = map(int, input().split())
p -= max(0, 20-p)
print((p+20)*t / (100-p))