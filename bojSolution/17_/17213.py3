n=int(input())
m=int(input())
f=[1,1]
for _ in range(2,50):
    f.append(f[_-1]*_)
N=n+(m-n)-1
R=m-n
print(int(f[N]/f[R]/f[N-R]))