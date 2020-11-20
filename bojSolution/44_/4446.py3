import sys
input = sys.stdin.readline

while 1:
    n = input()
    if not n: break
    for c in n.rstrip():
        if c in "AIYEOU":
            print("AIYEOU"[("AIYEOU".index(c)+3)%6], end="")
        elif c in "aiyeou":
            print("aiyeou"[("aiyeou".index(c)+3)%6], end="")
        elif c in "bkxznhdcwgpvjqtsrlmf":
            print("bkxznhdcwgpvjqtsrlmf"[("bkxznhdcwgpvjqtsrlmf".index(c)-10)%20], end="")
        elif c in "BKXZNHDCWGPVJQTSRLMF":
            print("BKXZNHDCWGPVJQTSRLMF"[("BKXZNHDCWGPVJQTSRLMF".index(c)-10)%20], end="")
        else: print(c, end="")
    print()