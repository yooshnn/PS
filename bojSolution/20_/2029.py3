import sys
input = sys.stdin.readline

"""
+1-+2-+3-+
1..1..1..1
3..4..5..6
+4-+5-+6.+
1..1..1..2
7..8..9..0
+7-+8-+9.+
2..2..2..2
1..2..3..4
+10+11+12+
"""

m = [0 for i in range(25)]
res = 0

board = []
for i in range(10):
    board.append(input().rstrip())

for r in range(4):
    for c in range(3):
        if board[r*3][1+c*3]=="-": m[1+c+r*3] = 1

for r in range(3):
    for c in range(4):
        if board[1+r*3][c*3]=="|": m[1+12+c+r*4] = 1

if m[1] and m[2] and m[3] and m[13] and m[16] and m[17] and m[20] and m[21] and m[24] and m[10] and m[11] and m[12]: res += 1
if m[1] and m[2] and m[13] and m[15] and m[17] and m[19] and m[7] and m[8]: res += 1
if m[2] and m[3] and m[14] and m[16] and m[18] and m[20] and m[8] and m[9]: res += 1
if m[4] and m[5] and m[17] and m[19] and m[21] and m[23] and m[10] and m[11]: res += 1
if m[5] and m[6] and m[18] and m[20] and m[22] and m[24] and m[11] and m[12]: res += 1
if m[1] and m[13] and m[14] and m[4]: res += 1
if m[2] and m[14] and m[15] and m[5]: res += 1
if m[3] and m[15] and m[16] and m[6]: res += 1
if m[4] and m[17] and m[18] and m[7]: res += 1
if m[5] and m[18] and m[19] and m[8]: res += 1
if m[6] and m[19] and m[20] and m[9]: res += 1
if m[7] and m[21] and m[22] and m[10]: res += 1
if m[8] and m[22] and m[23] and m[11]: res += 1
if m[9] and m[23] and m[24] and m[12]: res += 1

print(24-sum(m), res)
