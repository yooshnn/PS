from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    s = input()[::-1]
    r = 0
    for i, c in enumerate(s):
        if i%2 == 0:
            r += int(c)
        else:
            t = int(c)*2
            if t>=10:
                t = str(t)
                t = int(t[0])+int(t[1])
            r += t
    print("T" if r%10 < 1 else "F")