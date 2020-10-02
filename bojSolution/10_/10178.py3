for _ in range(int(input())):
    x,y=map(int,input().split())
    print("You get",x//y,"piece(s) and your dad gets",x-(x//y)*y,"piece(s).")