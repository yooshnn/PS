from sys import stdin
def input(): return stdin.readline().rstrip()
for _ in range(int(input())):
    x,y=input().split()
    print(x,"&",y,"are",end=" ")
    print(["NOT anagrams.","anagrams."][sorted(x)==sorted(y)])