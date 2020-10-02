from sys import stdin
def input(): return stdin.readline().rstrip()

Y = int(input()) + 1

while 1:
    ys = str(Y)
    if len(set(ys)) == len(ys):
        print(Y)
        break
    Y += 1