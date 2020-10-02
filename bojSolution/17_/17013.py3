from sys import stdin
def input(): return stdin.readline().rstrip()

board=[[1, 2],[3, 4]]

s = input()
h = s.count("H") % 2
v = s.count("V") % 2

if v == 1:
    board[0].reverse()
    board[1].reverse()
if h == 1:
    t = board[0][0]
    board[0][0] = board[1][0]
    board[1][0] = t
    t = board[0][1]
    board[0][1] = board[1][1]
    board[1][1] = t

print(*board[0])
print(*board[1])