def pan(str):
    li=[]
    l="abcdefghijklmnopqrstuvwxyz"
    for i in l:
        if i not in str:
            li.append(i)
    return sorted(set(li))

T=int(input())
for _ in range(T):
    s=input().lower()
    res=pan(s)
    if len(res)==0:
        print("pangram")
    else:
        print("missing ",end="")
        print(''.join(res))