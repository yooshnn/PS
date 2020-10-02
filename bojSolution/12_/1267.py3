from sys import stdin
N=int(stdin.readline())
M=0
Y=0
li=list(map(int,stdin.readline().split()))
for i in li:
    Y+=(i//30+1)*10
    M+=(i//60+1)*15
if M<Y:
    print("M",M)
elif M>Y:
    print("Y",Y)
else:
    print("Y M",Y)
