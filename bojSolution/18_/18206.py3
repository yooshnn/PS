import sys; input = sys.stdin.readline

s, p = input().rstrip(), input().rstrip()

if s==p:
    print("Yes")
    sys.exit(0)
elif len(s)==len(p)+1:
    for i in range(10):
        if s==p+str(i) or s==str(i)+p:
            print("Yes")
            sys.exit(0)
else:
    t = ""
    for c in s:
        if ord('a')<=ord(c)<=ord('z'):
            t += chr(ord(c)-ord('a')+ord('A'))
        elif ord('A')<=ord(c)<=ord('Z'):
            t += chr(ord(c)-ord('A')+ord('a'))
        else:
            t += c
    if t==p:
        print("Yes")
        sys.exit(0)
print("No")
