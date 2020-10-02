from sys import stdin
n,p,h=map(int,stdin.readline().split())
for _ in range(n):
    dollar = int(stdin.readline())
    if dollar<p:
        print("NTV: Dollar dropped by",p-dollar,"Oshloobs")
    elif dollar>h:
        print("BBTV: Dollar reached",dollar,"Oshloobs, A record!")
        h=dollar
    p=dollar