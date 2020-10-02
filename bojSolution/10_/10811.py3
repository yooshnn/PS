from sys import stdin
N,M=stdin.readline().split()
li=[int(x)+1 for x in range(int(N))]
for i in range(int(M)):
    s=[int(x)-1 for x in stdin.readline().split()]
    li[s[0]:s[1]+1]=li[s[0]:s[1]+1][::-1]
for i in li:
    print(i,end=" ")