while 1:
    a, o, b = input().split()
    a, b = int(a), int(b)
    if b==0: break

    if o=="W": a -= b
    else: a += b
    
    print(a if a>=-200 else "Not allowed")