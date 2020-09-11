from sys import stdin
T = int(stdin.readline())
li = []
for _ in range(T):
    garb = stdin.readline()
    li = [int(x) for x in stdin.readline().split()]
    se = set(li)
    for elem in li:
        if elem in se:
            se.remove(elem)
            print(elem,end=" ")
    print()