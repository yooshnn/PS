from sys import stdin

T=int(stdin.readline())
for _ in range(T):
    p1=p2=0
    n=int(stdin.readline())
    for i in range(n):
        x,y=stdin.readline().split()
        if x=="R" and y=="R":
            pass
        elif x=="R" and y=="P":
            p2+=1
        elif x=="R" and y=="S":
            p1+=1
        elif x=="P" and y=="R":
            p1+=1
        elif x=="P" and y=="P":
            pass
        elif x=="P" and y=="S":
            p2+=1
        elif x=="S" and y=="R":
            p2+=1
        elif x=="S" and y=="P":
            p1+=1
        elif x=="S" and y=="S":
            pass
    if p1==p2:
        print("TIE")
    elif p1>p2:
        print("Player 1")
    else:
        print("Player 2")