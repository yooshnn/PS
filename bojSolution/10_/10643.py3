from sys import stdin
input = stdin.readline

r = 0
s = [int(input()) for i in range(8)]
for i in range(8):
    temp = 0
    for j in range(4):
        temp += s[(i+j)%8]
    r = max(r, temp)
print(r)