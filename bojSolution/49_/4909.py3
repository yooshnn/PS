while 1:
    li=sorted(list(map(int,input().split())))
    if sum(li)==0:break
    li=li[1:-1]
    print("{0:g}".format(sum(li)/4))