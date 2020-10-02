from sys import stdin
def input(): return stdin.readline().rstrip()

d = dict()

N, P = map(int, input().split())
W, L, G = map(int, input().split())
m = 0

for _ in range(P):
    pre = input().split()
    if pre[1] == "W":
        d[pre[0]] = True

for _ in range(N):
    s = input()
    try:
        if d[s]: m += W
    except:
        m = max(0, m - L)

    if m >= G:
        print("I AM NOT IRONMAN!!")
        break
    elif _ == N-1:
        print("I AM IRONMAN!!")