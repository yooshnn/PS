import sys
input = sys.stdin.readline

for TEST in range(int(input())):
    n, res = int(input()), 0
    a, b = input().rstrip(), input().rstrip()

    for i in range(n):
        if a[i]!=b[i]: res += 1

    print("Case %d: %d"%(TEST+1, res))
