N=int(input())
for i in range(2*N)[::-2]:
    a="*"*i
    print(a.rjust(N+i//2))
for i in range(2*N)[3::2]:
    b="*"*i
    print(b.rjust(N+i//2))