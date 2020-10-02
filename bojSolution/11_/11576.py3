from sys import stdin
def input(): return stdin.readline().rstrip()

a, b = map(int, input().split())

m = int(input())
li = list(map(int, input().split()))
aToBase10 = 0
res = []

for i in range(1, m+1):
    aToBase10 += li[-i] * (a ** (i-1))

while aToBase10 > 0:
    res.append(aToBase10 % b)
    aToBase10 = aToBase10 // b

print(*res[::-1])