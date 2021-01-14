import sys; input = sys.stdin.readline

def oob(r: int, c: int):
    return (r<0 or c<0 or r>=8 or c>=8)
def ptos(r: int, c: int):
    return "abcdefgh"[r]+str(c+1)

d = [[False for r in range(8)] for c in range(8)]

a, b = map(int, input().split())
s = input()
r, c = ord(s[0])-ord("a"), int(s[1])-1

res = []

if not oob(r-a, c-b):
    res.append(ptos(r-a, c-b))
if not oob(r-a, c+b):
    res.append(ptos(r-a, c+b))
if not oob(r+a, c-b):
    res.append(ptos(r+a, c-b))
if not oob(r+a, c+b):
    res.append(ptos(r+a, c+b))
if not oob(r-b, c-a):
    res.append(ptos(r-b, c-a))
if not oob(r-b, c+a):
    res.append(ptos(r-b, c+a))
if not oob(r+b, c-a):
    res.append(ptos(r+b, c-a))
if not oob(r+b, c+a):
    res.append(ptos(r+b, c+a))

res = list(set(res))

res.sort()

print(len(res))
print(*res)
