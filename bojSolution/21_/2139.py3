while True:
    d,m,y=map(int,input().split())
    if d==0:break
    M=[31,28+int(y%4<1 and y%100>0 or y%400<1),31,30,31,30,31,31,30,31,30,31]
    print(sum(M[:m-1])+d)