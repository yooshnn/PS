import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    s = [*map(int, input().split())]
    row, col = set(), set()
    good = True
    for i in range(1, len(s), 2):
        if s[i] in row: good = False
        if s[i+1] in col: good = False
        row.add(s[i])
        col.add(s[i+1])
    print("SAFE" if good else "NOT SAFE")