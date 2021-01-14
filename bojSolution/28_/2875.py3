import sys; input = sys.stdin.readline

n, m, k = map(int, input().split())
team = 0

while 1:
    if n-2>=0 and m-1>=0 and (n-2)+(m-1)>=k:
        n -= 2
        m -= 1
        team += 1
    else:
        break

print(team)
