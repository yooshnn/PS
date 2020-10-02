a,b,c=map(int,input().split())
x,y=map(int,input().split())
t=(a-y)*(c-x)/x/y
print(t*b/(1+t))
