from sys import stdin
def input(): return stdin.readline().rstrip()

while 1:
    n = int(input())
    if n == 0: break
    s = input()
    li = [[] for x in range(n)]
    for i, c in enumerate(s):
        if (i//n)%2 == 0: li[i%n].append(c)
        else: li[n-1-i%n].append(c)
    for i in li:
        print(*i, sep="", end="")
    print()