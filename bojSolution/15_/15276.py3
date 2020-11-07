import sys
input = sys.stdin.readline

for _ in range(int(input())):
    s = input().rstrip()
    t, u = s, s
    while 1:
        if len(t)==6 and t[0]==t[5] and t[1]==t[4] and t[2]==t[3]:
            print(t)
            break
        if len(u)==6 and u[0]==u[5] and u[1]==u[4] and u[2]==u[3]:
            print(u)
            break
        t, u = str(int(t)-1), str(int(u)+1)
