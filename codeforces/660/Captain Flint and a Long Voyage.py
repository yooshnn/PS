from sys import stdin
T=int(stdin.readline())
for _ in range(T):
    n=int(stdin.readline())
    print("9"*(n-((n-1)//4+1))+"8"*((n-1)//4+1))
