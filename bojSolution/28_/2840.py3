from sys import stdin
def input(): return stdin.readline().rstrip()

isGood = True
n, k = map(int, input().split())
r = ["?"]*n
ptr = 0
for i in range(k):
    s, c = input().split(); s = int(s)
    ptr -= s
    ptr %= n
    if r[ptr] == c or (r[ptr] == "?" and c not in r):
        r[ptr] = c
    else:
        isGood = False
r *= 2
if isGood:
    print(*r[ptr:ptr+n], sep="")
else:
    print("!")