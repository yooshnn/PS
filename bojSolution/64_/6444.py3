import sys
input = sys.stdin.readline

def nameToRowCol(s):
    row_, col_ = "", ""
    row, col = 0, 0
    for c in s:
        if c.isalpha(): col_ += c
        else: row_ += c
    for c in col_:
        col = col*26 + ord(c)-64
    row = int(row_)
    return [row-1, col-1]

def isInt(s):
    try:
        int(s)
        return True
    except:
        return False

def proc(rc):
    r, c = rc
    if isInt(sheet[r][c]):
        sheet[r][c] = int(sheet[r][c])
        return sheet[r][c]
    else:
        expr = sheet[r][c][1:].split("+")
        res = 0
        for cell in expr:
            res += proc(nameToRowCol(cell))
        sheet[r][c] = res
        return sheet[r][c]

for TEST in range(int(input())):
    C, R = map(int, input().split())
    sheet = list()
    for r in range(R):
        sheet.append(input().split())
    for r in range(R):
        for c in range(C):
            proc([r, c])
    for r in range(R):
        for c in range(C):
            print(sheet[r][c], end=" ")
        print()
    del sheet