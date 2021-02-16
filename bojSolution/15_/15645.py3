import sys; input = sys.stdin.readline

N = int(input())
board = []
dp = [[0, 0, 0] for r in range(N)]
dp2 = [[0, 0, 0] for r in range(N)]
for r in range(N):
    board.append([*map(int, input().split())])

dp[0] = board[0]
dp2[0] = board[0]
for i in range(1, N):
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + board[i][0]
    dp[i][1] = max(dp[i-1]) + board[i][1]
    dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + board[i][2]
    dp2[i][0] = min(dp2[i-1][0], dp2[i-1][1]) + board[i][0]
    dp2[i][1] = min(dp2[i-1]) + board[i][1]
    dp2[i][2] = min(dp2[i-1][1], dp2[i-1][2]) + board[i][2]

print(max(dp[N-1]), min(dp2[N-1]))
