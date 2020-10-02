from sys import stdin

T = int(stdin.readline())
pattern = stdin.readline()[:-1].split("*")
lenl = len(pattern[0])
lenr = len(pattern[1])
flag=False

for _ in range(T):
    i = stdin.readline()[:-1]
    if len(i)<lenl+lenr:
        flag=False
    elif i[:lenl]==pattern[0] and i[len(i)-lenr:]==pattern[1]:
        flag=True
    else:
        flag=False
    print(["NE","DA"][flag])
