import sys
input = sys.stdin.readline

def solve(r, c):
    if c < 0 or c >= C or r >= R: return 0
    if dp[r][c] != 0: return dp[r][c]
    dp[r][c] = board[r][c] + max(solve(r+1, c-1), solve(r+1, c), solve(r+1, c+1))
    return dp[r][c]


R, C = map(int, input().split())
board = [[*map(int, input().split())] for _ in range(R)]
dp = [[0 for c in range(C)] for r in range(R)]

res = 0
for i in range(C):
    res = max(res, solve(0, i))

print(res)