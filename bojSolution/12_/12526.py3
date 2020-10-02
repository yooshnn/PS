from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    n = input()
    m = n.upper()
    print("Case #",_+1,": ",n,sep="",end=" is ruled by ")
    if m[-1]=="Y":
        print("nobody.")
    elif m[-1] in ["A","I","U","E","O"]:
        print("a queen.")
    else:
        print("a king.")