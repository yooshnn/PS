import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    s, u = input().split(); t = len(s)-int(u)%len(s)
    print("Shifting %s by %d positions gives us: %s"%(s, int(u), s[t:]+s[:t]))