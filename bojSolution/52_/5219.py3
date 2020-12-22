import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    rule, s = input().split(), input().split()
    print("Transformed strings: ", end="")
    for c in s:
        cur = c
        for i in range(0, len(rule), 2):
            t = cur.find(rule[i])
            if t!=-1:
                cur = cur[:t]+rule[i+1]+cur[t+len(rule[i+1])-1:]
        print(cur, end=" ")
    print()