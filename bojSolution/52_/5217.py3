from sys import stdin
T=int(stdin.readline())
for _ in range(T):
    n=int(stdin.readline())
    print("Pairs for ",n,": ",sep="",end="")
    for i in range(1,1+(n-1)//2):
        print(i,n-i,end="")
        if i<(n-1)//2:
            print(", ",end="")
    print()
