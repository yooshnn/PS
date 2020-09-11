from sys import stdin
T=int(stdin.readline())
for _ in range(T):
    n=int(stdin.readline())
    if n<=30:
        print("NO")
    else:
        if n-30!=6 and n-30!=10 and n-30!=14:
            print("YES")
            print("6 10 14",n-30)
        else:
            if n==36:
                print("YES")
                print("5 6 10 15")
            elif n==40:
                print("YES")
                print("6 9 10 15")
            elif n==44:
                print("YES")
                print("6 7 10 21")
            else:
                print("NO")
