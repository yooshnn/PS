from sys import stdin
flag=False
li=[]
test=[]
for _ in range(9):
    li.append(int(stdin.readline()))
for i in range(1,8):
    for j in range(0,9-i):
        del test[:]
        for k in range(9):
            if k!=j and k!=j+i:
                test.append(li[k])
        if sum(test)==100:
            for elem in sorted(test):
                print(elem)
            flag=True
        if flag==True:
            break
    if flag==True:
        break