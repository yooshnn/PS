from decimal import Decimal as D
t=0
for _ in range(int(input())):
    g,s,d,w=map(D,input().split())
    if ((g<=56 and s<=45 and d<=25) or g+s+d<=125) and w<=7:
        print(1)
        t+=1
    else:
        print(0)
print(t)