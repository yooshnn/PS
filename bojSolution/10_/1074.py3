from sys import stdin
res = 0
n,r,c = map(int,stdin.readline().split())
n = 2**n

x = 0
y = 0

while n>1:
    coo = 0
    if r>=y+n//2:
        coo += 2
    if c>=x+n//2:
        coo += 1

    res += (n//2)**2 * coo

    n/=2
    if coo == 1:
        x += n
    elif coo == 2:
        y += n
    elif coo == 3:
        x += n
        y += n
print(int(res))