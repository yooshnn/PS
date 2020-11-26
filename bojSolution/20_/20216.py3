import sys
input = sys.stdin.readline

while 1:
    s = input().rstrip()
    if s=="I quacked the code!": break
    try:
        print("*Nod*" if s[-1]=="." else "Quack!")
    except:
        pass
    sys.stdout.flush()