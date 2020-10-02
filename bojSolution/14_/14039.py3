from sys import stdin
def input(): return stdin.readline().rstrip()

isMagic = True
magicNo = 0
sq = []
n = 4

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

if isMagic:
    print("magic")
else:
    print("not magic")
