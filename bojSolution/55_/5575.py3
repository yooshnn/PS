from sys import stdin

def solve(li):
    s=li[5]-li[2]
    m=li[4]-li[1]
    h=li[3]-li[0]
    if s<0:
        m+=s//60
        s=60+s
    if m<0:
        h+=m//60
        m=60+m
    print(h,m,s)

A=list(map(int,stdin.readline().split()))
B=list(map(int,stdin.readline().split()))
C=list(map(int,stdin.readline().split()))
solve(A)
solve(B)
solve(C)