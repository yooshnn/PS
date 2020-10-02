def z(v):print(v,end=" ")
c=0;x=9901;m=99
for i in range(100):
    for j in range(100):
        if i==j:
            z(x);x+=1
        elif i<98:z(c+1if i%2<1else m*(i+1)-c%m);c+=1
        else:z(m*(i+1)-(c-1)%m if i%2<1else m*i+(c+m-1)%m+1);c+=1
    print()