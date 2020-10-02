n=int(input())
if n%2==0:
    print("I LOVE CBNU")
else:
    print("*"*n)
    for i in range((n+1)//2):
        print(" "*((n+1)//2-1-i),end="")
        print("*",end="")
        if i>0:
            print(" "*((i-1)*2+1),end="")
            print("*")
        else:
            print()