from sys import stdin
input = stdin.readline

v, m, t = map(int, input().split())
x, y = 0, 0

d = [0] * 4
# vold = v
#
# for i in range(t):
#     if i%4 == 0: y += v
#     if i%4 == 1: x += v
#     if i%4 == 2: y -= v
#     if i%4 == 3: x -= v
#     if i >= 4:
#         d[i%4] = v
#     v = (v * m) % 10
# print(x, y)
#
#
# print ("\n AND \n")
#
#
# x, y = 0, 0
# v = vold
#
# d = [0] * 4

for i in range(min(t, 8)):
    if i%4 == 0: y += v
    if i%4 == 1: x += v
    if i%4 == 2: y -= v
    if i%4 == 3: x -= v
    if i >= 4:
        d[i%4] = v
    v = (v * m) % 10

if t <= 8:
    print(x, y)
else:
    u = t - 8 - t%4;
    # print(x, y)
    # print(d, u)
    y += (d[0] - d[2]) * u//4
    x += (d[1] - d[3]) * u//4
    for i in range(t%4):
        if i == 0: y += d[0]
        if i == 1: x += d[1]
        if i == 2: y -= d[2]
        # print("*", x, y)


    print(x, y)
