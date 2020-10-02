li=[]
x,y=map(int,input().split())
for _ in range(x):
    li.append(str(input()))
for _ in range(x):
    print(li[_][::-1])
