from sys import stdin
def input(): return stdin.readline().rstrip()

def getZ(s):
    l,r=0,0
    ret=[0]*len(s)
    ret[0]=len(s)

    for i in range(1,len(s)):
        if i>r:
            l=r=i
            while r<len(s) and s[r]==s[r-l]:
                r+=1
            ret[i]=r-l
            r-=1
        else:
            if i+ret[i-l]<=r:
                ret[i]=ret[i-l]
            else:
                l=i
                while r<len(s) and s[r]==s[r-l]:
                    r+=1
                ret[i]=r-l
                r-=1

    return ret

S=input()[::-1]
Z=getZ(S)

M=int(input())
for _ in range(M):
    i=int(input())
    print(Z[len(S)-i])