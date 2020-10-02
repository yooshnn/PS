from sys import stdin
n=int(stdin.readline())
while True:
    x=int(stdin.readline())
    if x<1: break
    print(x,"is","NOT a" if x%n>0 else "a","multiple of",n,end=".\n")