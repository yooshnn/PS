from sys import stdin
li=[]

possible = True
N=int(stdin.readline())
for _ in range(N):
    temp=stdin.readline().split()
    li.append(temp)

ex=stdin.readline().split()
for word in ex:
    found = False
    for i in range(len(li)):
        if len(li[i]) > 0:
            if li[i][0] == word:
                li[i].pop(0)
                if len(li[i])==0:
                    li.pop(i)
                found = True
                break
    if not found:
        possible = False
        print("Impossible")
        break
if possible:
    if len(li)==0:
        print("Possible")
    else:
        print("Impossible")
