from sys import stdin
input = stdin.readline

n = int(input())
m = str(bin(n))
if n>=0:
    print(len(m)-2)
else:
    print(32)