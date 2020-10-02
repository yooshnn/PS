from sys import stdin
h,w=map(int,stdin.readline().split())
if w>h: #무조건 h가 w보다 크게
    temp=w
    w=h
    h=temp
res=0
if h>=w*3:
    res=max(res,w)
else:
    res=max(res,h/3)
res=max(res,w/2)
print(res)