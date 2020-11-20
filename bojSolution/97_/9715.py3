import sys
input = sys.stdin.readline

for TEST in range(int(input())):
    R, C = map(int, input().split())
    block = []
    res = 0
    for r in range(R):
        block.append(input().rstrip())
    for r in range(R):
        for c in range(C):
            if block[r][c] != "0":
                res += 2
            if r==0: res += int(block[r][c])
            else: res += max(0, int(block[r][c])-int(block[r-1][c]))

            if r==R-1: res += int(block[r][c])
            else: res += max(0, int(block[r][c])-int(block[r+1][c]))

            if c==0: res += int(block[r][c])
            else: res += max(0, int(block[r][c])-int(block[r][c-1]))

            if c==C-1: res += int(block[r][c])
            else: res += max(0, int(block[r][c])-int(block[r][c+1]))
    print(res)