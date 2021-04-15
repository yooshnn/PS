import sys; input = sys.stdin.readline

n = int(input())
s = [int(input()) for i in range(n)]
t = sum(s)

for c in s:
    if c==t-c:
        print(c)
        sys.exit(0)
print("BAD")