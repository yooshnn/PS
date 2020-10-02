s = input()
for i in range(26):
    try:
        print(s.index(chr(i+97)),end=" ")
    except:
        print(-1,end=" ")