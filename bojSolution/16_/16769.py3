import sys
input = sys.stdin.readline

bessie = [*map(int, input().split())]
elsie = [*map(int, input().split())]
mildred = [*map(int, input().split())]

for i in range(100):
    if i%3 == 0:
        amnt = min(bessie[1], elsie[0]-elsie[1])
        bessie[1] -= amnt
        elsie[1] += amnt
    elif i%3 == 1:
        amnt = min(elsie[1], mildred[0]-mildred[1])
        elsie[1] -= amnt
        mildred[1] += amnt
    else:
        amnt = min(mildred[1], bessie[0]-bessie[1])
        mildred[1] -= amnt
        bessie[1] += amnt

print(bessie[1], elsie[1], mildred[1])