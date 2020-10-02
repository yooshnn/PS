from sys import stdin
def input(): return stdin.readline().rstrip()
for _ in range(int(input())):
    a,b=input().split()
    print("Distances:",end=" ")
    for i in range(len(a)):
        dist=ord(b[i])-ord(a[i])
        if dist<0: dist=26+dist
        print(dist,end=" ")
    print()