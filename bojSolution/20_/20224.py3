import sys
input = sys.stdin.readline

def getFail(tar):
    ret, j = [0]*len(tar), 0
    for i in range(1,len(tar)):
        while j>0 and tar[i]!=tar[j]:
            j=ret[j-1]
        if tar[i]==tar[j]:
            j+=1
            ret[i]=j
    return ret

def KMP(src, tar):
    fail = getFail(tar)
    ret, j = 0, 0
    for i in range(len(src)):
        while j>0 and src[i]!=tar[j]:
            j=fail[j-1]
        if src[i]==tar[j]:
            if j==len(tar)-1:
                ret += 1
                j=fail[j]
            else:
                j+=1
    return ret

while 1:
    GO = int(input())
    if not GO: break

    src = "".join(input().split())
    print(KMP(src,"2020"))