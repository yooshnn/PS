import sys; input = sys.stdin.readline

while 1:
    s = input().rstrip()
    t = input().rstrip()

    if s=="E": break

    p1, p2 = 0, 0

    for i in range(len(s)):
        if s[i]=="R":
            if t[i]=="R": pass
            if t[i]=="S": p1 += 1
            if t[i]=="P": p2 += 1
        if s[i]=="S":
            if t[i]=="R": p2 += 1
            if t[i]=="S": pass
            if t[i]=="P": p1 += 1
        if s[i]=="P":
            if t[i]=="R": p1 += 1
            if t[i]=="S": p2 += 1
            if t[i]=="P": pass

    print("P1: %d\nP2: %d"%(p1, p2))