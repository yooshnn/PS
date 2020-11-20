import sys
input = sys.stdin.readline

rule = dict()
for i in range(int(input())):
    rule[i+1] = input().rstrip()

for i in range(int(input())):
    r = ""
    n = int(input())
    try:
        r = rule[n]
    except:
        r = "No such rule"
    print("Rule %d: %s"%(n, r))