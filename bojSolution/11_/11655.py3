from sys import stdin
s=str(stdin.readline()[:-1])
for i in s:
    if i.isalpha():
        if i.isupper():
            print(chr((ord(i)-65+13)%26+65),end="")
        else:
            print(chr((ord(i)-97+13)%26+97),end="")
    else:
        print(i,end="")
