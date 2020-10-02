from sys import stdin
def input(): return stdin.readline().rstrip()

d={}
d["."]="."
d["O"]="O"
d["-"]="|"
d["|"]="-"
d["/"]="\\"
d["\\"]="/"
d["^"]="<"
d["<"]="v"
d["v"]=">"
d[">"]="^"
s=[]
n,m=map(int,input().split())
for _ in range(n):
    s.append(list(input())[::-1])
for i in range(m):
    for j in range(n):
        print(d[s[j][i]],end="")
    print()