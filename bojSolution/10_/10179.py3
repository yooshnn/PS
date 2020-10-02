from sys import stdin
T=int(stdin.readline())
for _ in range(T):
    a=float(stdin.readline())*0.8
    print("$",end="")
    print("%.2f"%a)