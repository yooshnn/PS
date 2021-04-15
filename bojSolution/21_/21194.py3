import sys; input = sys.stdin.readline

n, k = map(int, input().split())
li = []
for i in range(n):
    li.append(-int(input()))
li.sort()
print(-sum(li[:k]))