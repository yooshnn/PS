from sys import stdin
def input(): return stdin.readline().rstrip()

n, k = int(input()), int(input())
r = n

for i in range(k):
    r *= 10
    r += n

print(r)