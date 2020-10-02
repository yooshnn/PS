from sys import stdin
li=sorted(list(map(int,stdin.readline().split())))
c1=abs((li[3]+li[2])-(li[1]+li[0]))
c2=abs((li[3]+li[1])-(li[2]+li[0]))
c3=abs((li[3]+li[0])-(li[2]+li[1]))
print(min(min(c1,c2),c3))
