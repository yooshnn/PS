from sys import stdin
N=int(stdin.readline())
request=[int(x) for x in input().split()]
response=set(request)
print(len(request)-len(response))