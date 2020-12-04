import sys
input = sys.stdin.readline

for TEST in range(int(input())):
    try:
        t = input()
        if len(t.split())>1:
            print("invalid input")
        else:
            t = t.strip()
            good = True
            for c in t:
                if not '0'<=c<='9': good = False
            print(int(t) if good else "invalid input")
    except:
        print("invalid input")