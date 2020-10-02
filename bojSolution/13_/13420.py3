from sys import stdin
T = int(stdin.readline())
while T > 0:
    T -= 1
    s = stdin.readline().split()
    equ_ = s[:3]
    equ = ""
    equ += s[0] + s[1] + s[2]
    goal = s[4]
    print(["wrong answer","correct"][eval(equ) == int(goal)])   