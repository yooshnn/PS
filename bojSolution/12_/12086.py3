from sys import stdin
def input(): return stdin.readline().rstrip()

name=[]

for _ in range(int(input())):
    del name[:]
    res=0

    for i in range(int(input())):
        cur = input()

        name.append(cur)
        name = sorted(name)

        if name[-1] != cur:
            res += 1

    print("Case #",_+1,": ",res,sep="")