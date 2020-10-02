from sys import stdin
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    D = int(input())
    name = []
    pres = []
    for d in range(D):
        name.append(input())
        pres.append(0)
    Q = int(input())
    for q in range(Q):
        s = input().split()
        for c in s:
            for n in range(D):
                if name[n] == c:
                    pres[n] = 1

    print("Test set ", _+1, ":", sep="")
    for i, n in enumerate(name):
        print(n,"is",end=" ")
        print("present" if pres[i] else "absent")
    print()