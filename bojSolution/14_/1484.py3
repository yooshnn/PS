from sys import stdin
import math
g=int(stdin.readline())
flag=False
i=math.ceil(math.sqrt(g))
while True:
    if i*i-(i-1)*(i-1)>g:
        break
    for a in range(1,i):
        if i*i-g==a*a:
            print(i)
            flag=True
    i+=1
if not flag:
    print(-1)
