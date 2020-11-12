import sys
input = sys.stdin.readline

while 1:
    line = input()
    if not line: break
    n, b, m = map(float, line.split())

    c = 0
    while n <= m:
        c += 1
        n *= (1+b/100)
    print(c)
