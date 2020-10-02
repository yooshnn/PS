from sys import stdin
s=""
t=0
while True:
    t=0
    s=str(stdin.readline().strip())
    if s=='0': break
    while True:
        for elem in s:
            t+=int(elem)
        if t<10:
            break
        s=str(t)
        t=0
    print(t)