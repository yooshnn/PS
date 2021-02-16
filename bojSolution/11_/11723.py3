import sys; input = sys.stdin.readline

a = [0 for i in range(21)]

for M in range(int(input())):
    s = input().split()
    if s[0]=="empty":
        for i in range(1, 21): a[i] = False
    elif s[0]=="all":
        for i in range(1, 21): a[i] = True
    else:
        s[1] = int(s[1])
        if s[0]=="add":
            a[s[1]] |= 1
        elif s[0]=="remove":
            a[s[1]] &= 0
        elif s[0]=="check":
            print(1 if a[s[1]] else 0)
        elif s[0]=="toggle":
            a[s[1]] ^= 1