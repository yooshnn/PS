import sys; input = sys.stdin.readline

n = int(input())

if n<=2: print(n)
else: print(2*n-2)

for i in range(n):
    print(1, i+1)
for i in range(n-2):
    print(n, i+2)
