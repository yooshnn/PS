from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    n, k = map(int, input().split())

    c = 0
    r = ""
    for i in range(k - 1):
        r += "1 "
        c += 1

    if c < n:
        if (n-c)%2 == 1:
            print("YES")
            print(r, n-c, sep="")
            continue
    else:
        print("NO")
        continue

    c = 0
    r = ""
    for i in range(k - 1):
        r += "2 "
        c += 2

    if c < n:
        if (n-c)%2 == 0:
            print("YES")
            print(r, n-c, sep="")
            continue
        else:
            print("NO")
            continue
    else:
        print("NO")
        continue
