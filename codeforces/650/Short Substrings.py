from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    b = input()
    if len(b) == 2:
        print(b)
    else:
        l=[]
        for i in range(len(b)-1):
            if (i+1)%2 == 0:
                l.append(b[i])
        print(b[0],*l,b[-1],sep="")
