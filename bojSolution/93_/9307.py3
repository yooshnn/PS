import sys; input = sys.stdin.readline

while 1:
    dp = [0 for x in range(102)]
    try: dp[1], dp[2], dp[3], Q = map(float, input().split()); Q = int(Q)
    except: break
    for i in range(4, Q+1):
        try:
            dp[i] = round(100*dp[i-3]*dp[i-2]/dp[i-1])/100
        except:
            dp[i-1] = 0.01
            dp[i] = round(100*dp[i-3]*dp[i-2]/dp[i-1])/100
    print("Month %d cost: $"%Q, end="")
    print(f"{dp[Q]:,.2f}")