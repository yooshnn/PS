import sys
import decimal
input = sys.stdin.readline
D = decimal.Decimal

def calc(x, y):
    r = D(x**2+y**2).sqrt()
    if r<=10: return 10
    for i in range(9):
        if r<=10+20*(i+1):
            return 9-i
    return 0

res = 0

for TEST in range(int(input())):
    res += calc(*map(int, input().split()))

print(res)