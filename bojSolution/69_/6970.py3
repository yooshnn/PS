import sys
input = sys.stdin.readline

for _ in range(int(input())):
    subCnt, verbCnt, objCnt = int(input()), int(input()), int(input())
    sub, verb, obj = [], [], []
    for __ in range(subCnt):
        t = input().rstrip()
        sub.append([t.lower(), t])
    for __ in range(verbCnt):
        t = input().rstrip()
        verb.append([t.lower(), t])
    for __ in range(objCnt):
        t = input().rstrip()
        obj.append([t.lower(), t])
    sub.sort(); verb.sort(); obj.sort()

    for i in range(subCnt):
        for j in range(verbCnt):
            for k in range(objCnt):
                print(" ".join([sub[i][1], verb[j][1], obj[k][1]]), end=".\n")
    print()