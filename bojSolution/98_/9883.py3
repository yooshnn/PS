import sys; input = sys.stdin.readline

x, y = map(int, input().split())
x, y = bin(x)[2:], bin(y)[2:]
if len(x)<18:
    x = "0"*(18-len(x))+x
if len(y)<18:
    y = "0"*(18-len(y))+y

r = ""
for i in range(18):
    r += x[i] + y[i]

print(int(r, 2))
