import sys; input = sys.stdin.readline

hole = 1
while 1:
    p, s = map(int, input().split())
    if p==0: break
    print("Hole #%d"%hole)
    hole += 1
    if s==1: print("Hole-in-one.")
    elif s==p: print("Par.")
    elif s<p:
        if p-s==1: print("Birdie.")
        if p-s==2: print("Eagle.")
        if p-s==3: print("Double eagle.")
    elif s>p:
        if s-p==1: print("Bogey.")
        if s-p>=2: print("Double Bogey.")
    print()