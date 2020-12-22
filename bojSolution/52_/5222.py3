import sys; input = sys.stdin.readline
import itertools

for TEST in range(int(input())):
    kw, plain = input().split()
    print("Ciphertext: ", end="")
    for i in range(len(plain)):
        c = plain[i]
        c = chr((ord(c)+ord(kw[i%(len(kw))])-2*ord("A"))%26+ord("A"))
        print(c, end="")
    print()