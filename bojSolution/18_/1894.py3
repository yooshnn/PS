from sys import stdin
while True:
    try:
        li=list(map(float,stdin.readline().split()))
        li=[[li[0],li[1]],[li[2],li[3]],[li[4],li[5]],[li[6],li[7]]]
        otr=[]
        for i in range(3):
            for j in range(i+1,4):
                if li[i]==li[j]:
                    dup=li[i]
                    dupid=[i,j]
        for i in range(4):
            if i not in dupid:
                otr.append(li[i])
        print(format(otr[0][0]+otr[1][0]-dup[0],".3f"),format(otr[0][1]+otr[1][1]-dup[1],".3f"))
    except:
        break
