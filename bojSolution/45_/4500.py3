import sys
input = sys.stdin.readline

for TEST in range(int(input())):
    d1, d2 = dict(), dict()
    name = input().split()
    for i, n in enumerate(name):
        d1[i] = n
        d2[n] = i
    b = d2[input().rstrip()]
    n = (b + int(input()) - 1)%len(name)
    print(d1[n])