import sys
input = sys.stdin.readline

m = dict()
prime = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317]
n = int(input())
s = input().split()

for i in range(0, len(s), 2):
    cur = abs(int(s[i]))
    if cur==0:
        print("mint chocolate"); sys.exit(0)
    if i==0 or s[i-1]=="*":
        for p in prime:
            while cur%p==0:
                try: m[p] += 1
                except: m[p] = 1
                cur //= p
    if cur!=1 and s[i-1]=="*":
        try: m[cur] += 1
        except: m[cur] = 1

res = True

for i in range(2, len(s), 2):
    cur = abs(int(s[i]))
    if cur==1: continue
    if s[i-1]=="/":
        for p in prime:
            while cur%p==0:
                try:
                    m[p] -= 1
                    if m[p]<0: res = False
                except:
                    res = False
                cur //= p
        if cur!=1:
            try:
                m[cur] -= 1
                if m[cur]<0: res = False
            except:
                res = False
    if not res: break

print(["toothpaste", "mint chocolate"][res])