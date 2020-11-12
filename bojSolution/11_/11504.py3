import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, m = map(int, input().split())
    x = int("".join(input().split()))
    y = int("".join(input().split()))
    s = "".join(input().split())
    s = s+s
    s = s[:-1]
    res = 0
    for i in range(n):
        if x<=int(s[i:i+m])<=y:
            res += 1
    print(res)