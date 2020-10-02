from sys import stdin
def input(): return stdin.readline().rstrip()

def solve(li):
    if len(li) == 1: return [""]
    ret=list()
    for s in range(len(li)):
        song = li[s]
        col = li[:s]+li[s+1:]
        c = []
        for nameL in range(1,len(song)+1):
            for i in range(0,len(song)-nameL+1):
                temp = song[i:i+nameL]
                if all(temp not in col_item for col_item in col):
                    c.append(temp)
            if len(c)>0:
                break
        if len(c)>0:
            ret.append(sorted(c)[0])
        else:
            ret.append(":(")

    return ret

for _ in range(int(input())):
    N = int(input())
    li = []
    for i in range(N):
        li.append(input().upper())

    res = solve(li)

    print("Case #%d:"%(_+1))
    for r in res:
        if r != ":(": print('"',r,'"',sep="")
        else: print(":(")
