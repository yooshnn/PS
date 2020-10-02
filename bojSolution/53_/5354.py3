t=int(input())
for _ in range(t):
    s=int(input())
    print("#"*s)
    for i in range(s-2):
        print("#"+"J"*(s-2)+"#")
    if s>1: print("#"*s)
    print()