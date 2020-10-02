l=list(map(int,input().split()))
if sum(l)>99:
    print("OK")
else:
    if l[0] < l[1] and l[0] < l[2]:
        print("Soongsil")
    elif l[1] < l[0] and l[1] < l[2]:
        print("Korea")
    else:
        print("Hanyang")