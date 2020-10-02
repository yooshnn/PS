from sys import stdin
n=int(stdin.readline())
for _ in range(n):
    s=str(stdin.readline()[:-1])
    print("String #",_+1,sep="")
    for i in s:
        print(chr((ord(i)-65+1)%26+65),end="")
    if _<n-1:
        print()
        print()