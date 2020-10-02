from sys import stdin
input = stdin.readline

while 1:
    d, p, n = int(input()), 0, 0
    if d == 0: break
    s = input().rstrip().upper().replace(" ","")
    r = ["" for i in range(len(s))]
    for c in s:
        r[p] = c
        p += d
        if p>=len(s):
            n += 1
            p = n
    print("".join(r))