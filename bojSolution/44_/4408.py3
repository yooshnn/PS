import sys
input = sys.stdin.readline

n = int(input())
nameToParty = {}
vote = {}

for _ in range(n):
    name, party = input().rstrip(), input().rstrip()
    nameToParty[name] = party
    vote[name] = 0

q = int(input())
for _ in range(q):
    name = input().rstrip()
    try: vote[name] += 1
    except: pass

M = -1
res = ""

for keys in vote:
    if vote[keys]>M:
        M = vote[keys]
        res = keys
    elif vote[keys]==M:
        res = "tie"

print("tie" if res=="tie" else nameToParty[res])
