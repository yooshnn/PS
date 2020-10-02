from sys import stdin

T = int(stdin.readline())
for _ in range(T):
    li = list(input().split())
    a = (ord(li[0][0])-ord('A')+1+int(li[0][1]))%2
    a = 1-a
    b = int(li[1])%2
    if ((int(li[1])-1)//8)%2==1:
        b = 1-b
    print(["NO","YES"][a==b])
