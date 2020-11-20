import sys
input = sys.stdin.readline

for TEST in range(int(input())):
    d = dict()
    sCnt, pCnt, tCnt, qCnt = 0, 0, 0, 0
    s = sorted(map(int, input().split()))
    for c in s:
        try:
            d[c] += 1
        except:
            d[c] = 1
        if d[c]==1:
            sCnt += 1
        if d[c]==2:
            pCnt += 1
            sCnt -= 1
        if d[c]==3:
            tCnt += 1
            pCnt -= 1
        if d[c]==4:
            qCnt += 1
            tCnt -= 1
    res = [sCnt, pCnt, tCnt, qCnt]
    if res==[6,0,0,0]: print("single")
    elif res==[4,1,0,0]: print("one pair")
    elif res==[2,2,0,0]: print("two pairs")
    elif res==[0,3,0,0]: print("three pairs")
    elif res==[3,0,1,0]: print("one triple")
    elif res==[0,0,2,0]: print("two triples")
    elif res==[2,0,0,1]: print("tiki")
    elif res==[0,1,0,1]: print("tiki pair")
    else: print("full house")