from sys import stdin
def input(): return stdin.readline().rstrip()

a, b = map(int, input().split())
res = 1

for i in range(a, b + 1):
    res *= (i*(i+1))//2
    res %= 14579

print(res)
