from sys import stdin
input = stdin.readline

n = int(input())
s1 = input().rstrip()
s2 = input().rstrip()
r = ""

if n%2 == 1:
    for j in range(len(s1)):
        r += str(1-int(s1[j]))
    print("Deletion succeeded" if r==s2 else "Deletion failed")
else:
    print("Deletion succeeded" if s1==s2 else "Deletion failed")
