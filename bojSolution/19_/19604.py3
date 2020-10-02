from sys import stdin
def input(): return stdin.readline().rstrip()

minX, minY = 101, 101
maxX, maxY = -1, -1
for _ in range(int(input())):
    x, y = map(int, input().split(','))
    if x < minX: minX = x
    if y < minY: minY = y
    if x > maxX: maxX = x
    if y > maxY: maxY = y

print(minX-1, minY-1, sep=',')
print(maxX+1, maxY+1, sep=',')