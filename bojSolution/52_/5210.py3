import sys
input = sys.stdin.readline

for TEST in range(int(input())):
    raw = [input().rstrip() for i in range(int(input()))]
    dat = [i.lower() for i in raw]
    code = input().lower().rstrip()

    print("Data Set %d:"%(TEST+1))
    for x, building in enumerate(dat):
        j = 0
        for i in building:
            if i==code[j]:
                j += 1
                if j==len(code):
                    print(raw[x])
                    break