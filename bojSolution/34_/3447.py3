import sys
import collections
input = sys.stdin.readlines
deque = collections.deque

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
    srcLen, tarLen = len(src), len(tar)
    dp = [0]*srcLen
    ptr, j = 0, 0
    for i in range(srcLen):
        while j>0 and src[i]!=tar[j]: j = fail[j-1]
        if src[i]==tar[j]: j += 1
        res[ptr] = src[i]
        dp[ptr] = j
        if j==tarLen:
            ptr -= tarLen
            j = dp[ptr]
        ptr += 1
    return ptr

code = input()
for src in code:
    res = [""]*len(src)
    reslen = KMP(src, "BUG")
    print("".join(res[:reslen]), end="")