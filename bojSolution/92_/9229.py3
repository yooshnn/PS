from sys import stdin
def input(): return stdin.readline().rstrip()

while 1:
    res = True
    wl = []
    while 1:
        w = input()
        if w=="#": break
        wl.append(w)
    if len(wl) == 0:
        break

    for i in range(1, len(wl)):
        if len(wl[i]) != len(wl[i-1]):
            res = False
            break
        md = 0
        for j in range(len(wl[i])):
            if wl[i][j] != wl[i-1][j]:
                md += 1
        if md != 1:
            res = False
            break

    print("Correct" if res else "Incorrect")