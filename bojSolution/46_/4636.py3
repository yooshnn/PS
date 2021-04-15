import sys; input = sys.stdin.readline

TEST = True
while TEST:
    n = int(input())
    if n==-1: break
    pp = []
    for i in range(n):
        s = input().split()
        pp.append((int(s[0])*int(s[1])*int(s[2]), s[3]))
    pp.sort()
    print(" took clay from ".join([pp[-1][1], pp[0][1]]), end=".\n")
