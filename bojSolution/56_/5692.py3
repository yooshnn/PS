from sys import stdin
from math import factorial
def input(): return stdin.readline().rstrip()
while 1:
    s=input()
    if s=="0":break
    r=0
    for i in range(len(s)):
        r+=int(s[i])*factorial(len(s)-i)
    print(r)