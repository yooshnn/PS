from sys import stdin

d={}
d[1]=[]
DN=int(stdin.readline())
M=int(stdin.readline())
for _ in range(M):
    friend=list(map(int,stdin.readline().split()))
    try:
        d[friend[0]].append(friend[1])
    except:
        d[friend[0]]=[friend[1]]
    try:
        d[friend[1]].append(friend[0])
    except:
        d[friend[1]]=[friend[0]]

ilchon=[]
echon=[]
if len(d[1])==0:
    print(0)
else:
    for i in d[1]:
        ilchon.append(i)
    for i in ilchon:
        try:
            for j in d[i]:
                echon.append(j)
        except:
            pass
    chingu=ilchon+echon
    if 1 in chingu:
        print(len(set(chingu))-1)
    else:
        print(len(set(chingu)))
