import sys
input = sys.stdin.readline

while 1:
    game = input().rstrip()
    if game=="#": break
    A, B = 0, 0
    a, b = 0, 0
    for c in game:
        if c == "A": a += 1
        else: b += 1
        if a>3 and a-b>1:
            A += 1
            a, b = 0, 0
        if b>3 and b-a>1:
            B += 1
            a, b = 0, 0
    print("A",A,"B",B)