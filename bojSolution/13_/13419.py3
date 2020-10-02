from sys import stdin

T = int(stdin.readline())
while T > 0:
    T -= 1

    text = stdin.readline()[:-1]
    a = ""
    b = ""

    if len(text)%2 == 0:
        for i in range(int(len(text)/2)):
            a += text[i*2]
            b += text[i*2+1]
    else:
        for i in range(len(text)):
            a += text[(i*2)%len(text)]
            b += text[(i*2+1)%len(text)]
    print(a)
    print(b)