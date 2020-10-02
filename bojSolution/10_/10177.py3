from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    isMagic = True
    magicNo = 0
    sq = []
    n = int(input())

    for i in range(n):
        sq.append(list(map(int, input().split())))

    magicNo = sum(sq[0])

    for col in sq:
        if sum(col) != magicNo: isMagic = False
    for c in range(n):
        temp = 0
        for r in range(n):
            temp += sq[r][c]
        if temp != magicNo: isMagic = False

    temp = 0
    for c in range(n):
        temp += sq[c][c]
    if temp != magicNo: isMagic = False

    if isMagic:
        print("Magic square of size", n)
    else:
        print("Not a magic square")