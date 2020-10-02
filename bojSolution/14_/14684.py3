from sys import stdin
def input(): return stdin.readline().rstrip()

def isAS(t):
    t = str(t)
    diff = int(t[1]) - int(t[0])
    for i in range(2, len(t)):
        if int(t[i]) - int(t[i-1]) != diff:
            return False
    return True

d = int(input())
time = 1201
res = 0

if d >= 1440:
    res += 62 * (d // 1440)
    d %= 1440

for i in range(d):
    res += isAS(time)

    time += 1
    if time % 100 == 60:
        if time == 1260:
            time = 100
        else:
            time += 100 - 60

print(res)