import sys; input = sys.stdin.readline

n = int(input())
s = [*map(int, input().split())]
good = True

for i in range(0, n-2):
    for j in range(i+1, n-1):
        for k in range(j+1, n):
            if (s[i]-s[j])%s[k]!=0:
                good = False
            if (s[i]-s[k])%s[j]!=0:
                good = False
            if (s[j]-s[i])%s[k]!=0:
                good = False
            if (s[j]-s[k])%s[i]!=0:
                good = False
            if (s[k]-s[i])%s[j]!=0:
                good = False
            if (s[k]-s[j])%s[i]!=0:
                good = False

print("yes" if good else "no")
