import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    n, k = map(int, input().split())
    m = 0
    s = input().rstrip()
    for i in range(n//2):
        if s[i]!=s[n-1-i]: m += 1
    print("Case #%d: %d"%(TEST+1, abs(m-k)))
