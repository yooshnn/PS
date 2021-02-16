import sys; input = sys.stdin.readline

puts = lambda x: print(x, end="")
ws = ' '

for TEST in range(int(input())):
    s = input()
    for i, c in enumerate(s):
        if c==':':
            if i!=0 and s[i-1]!=' ': puts(ws)
            puts(c)
            if s[i+1] not in [' ', '\n', ':', '-']: puts(ws)
        elif c=='-':
            if i!=0 and s[i-1]!=' ': puts(ws)
            puts(c)
            if s[i+1] not in [' ', '\n', ':', '-']: puts(ws)
        else: puts(c)
