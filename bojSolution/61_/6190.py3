import sys
input = sys.stdin.readline

n = int(input())
r = 0

while n!=1:
    if n%2==1: n = n*3+1
    else: n //= 2
    r += 1

print(r)