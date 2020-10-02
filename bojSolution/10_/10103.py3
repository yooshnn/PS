c,s=100,100
for _ in range(int(input())):
    x,y=map(int,input().split())
    if x>y:
        s-=x
    if y>x:
        c-=y
print(c,s,sep="\n")