s,d=map(int,input().split())
a=(s+d)/2
b=(s-d)/2
if a%1==0 and b%1==0 and a>=0 and b>=0:
    print(int(a),int(b))
else:
    print(-1)