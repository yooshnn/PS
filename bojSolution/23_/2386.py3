from sys import stdin
def input(): return stdin.readline()

while True:
    s=input().split()
    t=s[0]
    if t=='#': break
    del s[0]
    s=str(s)
    print(t,s.count(t)+s.count(chr(ord(t)+ord('A')-ord('a'))))