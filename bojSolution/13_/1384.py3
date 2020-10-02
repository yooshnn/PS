from sys import stdin
def input(): return stdin.readline().rstrip()

name=[]
message=[]
T=0
while 1:
    T+=1
    del name[:]
    del message[:]
    flag=False
    studno=int(input())
    if studno==0: break
    print("Group",T)
    for i in range(studno):
        line=input().split()
        name.append(line[0])
        message.append(line[1:])
    for i in range(studno):
        parse=message[i]
        for j in range(len(parse)):
            if parse[j]=="N":
                flag=True
                print(name[i-(j+1)],"was nasty about",name[i])
    if not flag:
        print("Nobody was nasty")
    print()