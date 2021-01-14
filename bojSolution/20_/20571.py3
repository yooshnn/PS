import sys; input = sys.stdin.readline

s, f = input().split(); f = int(f)

if s=="residential":
    if f<2: print(0)
    elif f<6: print(1)
    elif f<11: print(2)
    elif f<16: print(3)
    else: print(4)
elif s=="commercial":
    if f<2: print(0)
    elif f<8: print(1)
    elif f<15: print(2)
    else: print(3)
elif s=="industrial":
    if f<2: print(0)
    elif f<5: print(1)
    elif f<9: print(2)
    elif f<13: print(3)
    elif f<17: print(4)
    else: print(5)