import sys; input = sys.stdin.readline

N = int(input())
s = input().rstrip()
p = 0

for i in range(N):
    m, t = -1, '_'
    for c in "RGB":
        if s.find(c, p)>m:
            m = s.find(c, p)
            t = c
    print(t, end="")
    p = m+1