import sys
input = sys.stdin.readline

n = int(input())
a,b,c,d,e,f = map(int, input().split())
s3 = min(a+b+d, b+d+f, d+e+f, a+d+e, c+e+f, b+c+f, a+b+c, a+c+e)
s2 = min(a+b, b+f, f+e, e+a, a+c, b+c, f+c, e+c, d+a, d+b, d+f, d+e)

if n==1:
    print(sum([a,b,c,d,e,f]) - max(a,b,c,d,e,f))
elif n==2:
    print(4*s3 + 4*s2)
else:
    print(min(a,b,c,d,e,f)*((n-2)**2 + 4*(n-2)*(n-1)) + s2*(4*(n-2) + 4*(n-1)) + s3*4)