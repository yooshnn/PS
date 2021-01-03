import sys; input=sys.stdin.readline

n = int(input())
r = 0
for i in range(1, n):
    r += n*i+i
print(r)