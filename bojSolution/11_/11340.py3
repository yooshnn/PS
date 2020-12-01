import sys
input = sys.stdin.readline

for TEST in range(int(input())):
    s = [*map(int, input().split())]
    if s[0]*0.15+s[1]*0.20+s[2]*0.25+100*0.40 < 90:
        print("impossible")
    else:
        r = 100
        for i in range(100, -1, -1):
            if s[0]*0.15+s[1]*0.20+s[2]*0.25+i*0.40 >= 90: r = i
            else: break
        print(r)