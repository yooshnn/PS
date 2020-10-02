from sys import stdin
input = stdin.readline

a, b = list(map(int, input().split())), list(map(int, input().split()))
a_, b_ = 0, 0
st = 0

for i in range(9):
    a_ += a[i];
    if a_>b_ and st==0:
        st = 1
    b_ += b[i]  
    if a_<b_ and st==1:
        st = 2
print("Yes" if st == 2 else "No")
