from sys import stdin
def input(): return stdin.readline().rstrip()

Q = (input() == "1")
N = int(input())
g1 = sorted(map(int, input().split()))
g2 = sorted(map(int, input().split()))
res = 0

if Q:
    for i in range(N):
        res += max(g1[i], g2[i])
    print(res)
else:
    g2 = g2[::-1]
    for i in range(N):
        res += max(g1[i], g2[i])
    print(res)