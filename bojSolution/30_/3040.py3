li=[]
for _ in range(9):
    li.append(int(input()))
ky=sum(li)-100
for i in range(9):
    for j in range(i+1,9):
        if li[i]+li[j]==ky:
            for k in range(9):
                if k!=i and k!=j:
                    print(li[k])
            i=j=100
            break
