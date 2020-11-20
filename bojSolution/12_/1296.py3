import sys
input = sys.stdin.readline

def calc(a):
    L, O, V, E = a.count("L"), a.count("O"), a.count("V"), a.count("E")
    return ((L+O)*(L+V)*(L+E)*(O+V)*(O+E)*(V+E))%100

o = input().rstrip()
g = []
for _ in range(int(input())):
    g.append(input().rstrip())
g.sort()

res = ""
M = -1
for i in g:
    if calc(o+i)>M:
        M = calc(o+i)
        res = i
        
print(res)