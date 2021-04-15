import sys; input = sys.stdin.readline

test = 1
while 1:
    s = int(input())
    if s==0: break
    print("File #%d"%test)
    test += 1

    s = (s + 1) // 2
    s += (s + 1) // 2

    res = 0
    while s>0:
        s -= 30000*62
        res += 1

    print("John needs %d floppies.\n"%res)