import sys
input = sys.stdin.readline

for _ in range(int(input())):
    s = input().rstrip()
    dp = [0 for i in range(len(s))]
    for i in range(len(s)):
        dp[i] = len(set(s[max(0, i-1):min(len(s), i+2)]))
        if i>0: dp[i] = (dp[i] * dp[i-1]) % 1000000007
    print("Case #%d: %s"%(_+1, dp[-1]))
