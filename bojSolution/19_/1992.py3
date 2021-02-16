import sys; input = sys.stdin.readline

N = int(input())
board = [[int(i) for i in input().rstrip()] for r in range(N)]

def solve(R: int, C: int, S: int):
    v = 0
    for r in range(R, R+S):
        for c in range(C, C+S):
            v += board[r][c]
    if v==S*S: return "1"
    elif v==0: return "0"
    else:
        d = S//2
        return "(" + solve(R, C, d) + solve(R, C+d, d) + solve(R+d, C, d) + solve(R+d, C+d, d) + ")"

print(solve(0, 0, N))