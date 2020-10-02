from sys import stdin
def input(): return stdin.readline()

for _ in range(int(input())):
    p=input()
    q=input()
    res=0
    for i in range(len(p)):
        res+=p[i]!=q[i]
    print("Hamming distance is {}.".format(res))