while 1:
    li=[0]*26
    s=input()
    if s=='#':break
    for i in s:
        if ord(i)>=ord('a') and ord(i)<=ord('z'):
            li[ord(i)-ord('a')]=1
        elif ord(i)>=ord('A') and ord(i)<=ord('Z'):
            li[ord(i)-ord('A')]=1
    print(sum(li))