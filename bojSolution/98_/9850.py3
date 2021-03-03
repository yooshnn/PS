import sys; input = sys.stdin.readline

s = input().rstrip()

for i in range(26):
    temp = []
    for c in s:
        if 'A'<=c<='Z':
            temp.append(chr((ord(c)-ord('A')+i)%26+ord('A')))
        else:
            temp.append(c)
    plaintext = "".join(temp)
    if plaintext.find("CHIPMUNKS")!=-1 and plaintext.find("LIVE")!=-1:
        print(plaintext)
        break