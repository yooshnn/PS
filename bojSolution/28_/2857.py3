from sys import stdin
def input(): return stdin.readline().rstrip()
li=[]
for _ in range(5):
    s=input()
    if s.count("FBI")!=0:
        li.append(_+1)
if len(li)>0:
    for i in li:
        print(i,end=" ")
else:
    print("HE GOT AWAY!")