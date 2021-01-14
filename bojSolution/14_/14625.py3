import sys; input = sys.stdin.readline

h0, m0 = map(int, input().split())
h1, m1 = map(int, input().split())
x = int(input())
r = 0

while True:
    if x in [h0%10, m0%10, h0//10, m0//10]: r += 1
    if h0==h1 and m0==m1: break
    m0 += 1
    if m0==60:
        h0 += 1
        m0 = 0


print(r)
