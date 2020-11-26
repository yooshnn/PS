import sys
input = sys.stdin.readline

r, c = map(int, input().split())

def go(R, C):
    global r, c
    print(r + R, c + C)
    r += R
    c += C

print(r, c)
while r>0: go(-1, 0)
while c>0: go(0, -1)

for i in range(10):
    if i&1:
        for j in range(9):
            go(0, -1)
    else:
        for j in range(9):
            go(0, 1)
    if i!=9: go(1, 0)