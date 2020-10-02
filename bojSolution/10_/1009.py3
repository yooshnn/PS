d = [[10],[1],[6,2,4,8],[1,3,9,7],[6,4],[5],[6],[1,7,9,3],[6,8,4,2],[1,9]]
h = int(input())
for i in range(0,h):
    a,b=input().split()
    a = int(a)
    b = int(b)
    print(d[a%10][b%len(d[a%10])])