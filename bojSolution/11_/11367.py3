import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    n, s = input().split(); s = int(s)
    print(n, end=" ")
    if s>=97: print("A+")
    elif s>=90: print("A")
    elif s>=87: print("B+")
    elif s>=80: print("B")
    elif s>=77: print("C+")
    elif s>=70: print("C")
    elif s>=67: print("D+")
    elif s>=60: print("D")
    else: print("F")