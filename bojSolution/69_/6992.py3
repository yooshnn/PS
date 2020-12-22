import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    s = [*map(int, input().split())]
    del s[0]
    t = [str(x) for x in s]
    d = 2147483647
    for i in range(1, len(s)):
        if d==2147483647: d = s[i]-s[i-1]
        else:
            if d!=s[i]-s[i-1]: d=2147483648
    if d<2147483648:
        if d==2147483647: d=0
        u = [str(s[-1]+d*i) for i in range(1, 6)]
        print("The next 5 numbers after [%s] are: [%s]"%(", ".join(t), ", ".join(u)))
    else:
        print("The sequence [%s] is not an arithmetic sequence."%", ".join(t))