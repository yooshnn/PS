for _ in range(int(input())):
    print("Data Set",_+1,end=":\n")
    x,y=map(int,input().split())
    if y>=x:
        print("no drought")
    else:
        rep=0
        while x>y*5:
            rep+=1
            x/=5
        s="mega "*rep+"drought"
        print(s)
    print()