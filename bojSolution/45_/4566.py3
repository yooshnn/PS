import sys
input = sys.stdin.readline

while 1:
    line = input()[:-1]
    if line=="END": break
    a, b = "", ""
    good = True
    qo = 0
    if line[0] !="\"": good = False
    for c in line:
        if qo==-1:
            if c!=" ":
                good = False
            qo = 2
            continue
        if c=="\"":
            if qo==0:
                qo = 1
                continue
            if qo==1:
                qo = -1
                continue
            good = False
        if qo==0:
            good = False
        if qo==1:
            a += c
        if qo==2:
            b += c
    print("Quine("+a+")" if a !="" and a==b and good else "not a quine")
