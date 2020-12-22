import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    n = int(input())
    s = [[*map(int, input().split())] for x in range(n)]
    for i in range(n): s[i].append(i)
    res = 1

    s = sorted(s, key=lambda x: x[0])
    ms = s[0][1]
    for i in range(1, n):
        if ms>s[i][1]:
            ms = s[i][1]
            res += 1

    print(res)
