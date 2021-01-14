import sys; input = sys.stdin.readline

n, m = map(int, input().split())
a, b = [m//n for _ in range(n)], 6**n
x = 1

for i in range(m-n*(m//n)): a[i] += 1
for i in range(n): x *= a[i]

print(x/b)