from sys import stdin
a,s,d,f,g=map(int,stdin.readline().split())
print((a*a+s*s+d*d+f*f+g*g)%10)