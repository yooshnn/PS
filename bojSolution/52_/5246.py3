import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    r = {}
    s = [*map(int, input().split())]
    for i in range(2, 2*s[0]+1, 2):
        try: r[s[i]]+=1
        except: r[s[i]]=1
    print(max(r.values()))