import sys; input = sys.stdin.readline

n, k = map(int, input().split())
s = sum([int(input()) for i in range(k)])
s0, s1 = s-3*(n-k), s+3*(n-k)
print(s0/n, s1/n)