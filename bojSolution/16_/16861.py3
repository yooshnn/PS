from sys import stdin
def input(): return stdin.readline().rstrip()

n = int(input())
while 1:
    s = str(n)
    t = 0
    for c in s:
        t += ord(c) - ord("0")
    if n%t == 0:
        print(n)
        break
    n += 1