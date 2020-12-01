import sys
input = sys.stdin.readline

while 1:
    n = int(input())
    if n==0: break
    s = set()
    for i in range(n):
        t = [*map(int, input().split())]
        for c in t:
            s.add(c)
    print("Yes" if len(s)==49 else "No")