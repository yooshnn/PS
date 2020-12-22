import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    s, t = input().split()
    a, b = 0, 0
    for i in range(4):
        if t[i]==s[i]: a+=1
        else:
            for j in range(4):
                if t[i]==s[j] and t[i]!=t[j]:
                    b+=1
                    break
    print("For secret = %s and guess = %s, %d circles and %d squares will light up."%(s,t,a,b))