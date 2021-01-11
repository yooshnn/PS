import sys; input = sys.stdin.readline

while 1:
    pages = int(input())
    if pages==0: break
    p = [0 for _ in range(pages)]
    s = input().rstrip().split(",")
    for c in s:
        if c.find("-")==-1:
            try: p[int(c)-1] = 1
            except: pass
        else:
            f, t = map(int, c.split("-"))
            if f>t: continue
            f, t = f-1, t-1
            for i in range(f, t+1):
                if i>=0 and i<pages:
                    p[i] = 1
    print(sum(p))
