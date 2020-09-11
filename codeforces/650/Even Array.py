from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    c = 0
    d = 0

    for i in range(len(a)):
        if a[i]%2 != i%2:
            if i%2 == 0:
                c += 1
            else:
                d += 1

    if c != d:
        print(-1)
    else:
        print(c)
