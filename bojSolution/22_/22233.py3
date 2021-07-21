import sys; input = sys.stdin.readline

N, M = map(int, input().split())
keywords = set([input().rstrip() for i in range(N)])
for i in range(M):
    for x in input().rstrip().split(","):
        if x in keywords: keywords.remove(x)
    print(len(keywords))