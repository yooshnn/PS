import sys; input = sys.stdin.readline

while 1:
    n = input()
    if not n: break
    n = int(n)
    t, c = 1, 1
    while t%n != 0:
        t = 10*t + 1
        c += 1
    print(c)