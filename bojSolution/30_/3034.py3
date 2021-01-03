n, w, h = map(int, input().split())
d = w*w+h*h

for i in range(n):
    x = int(input())
    print("DA" if x*x<=d else "NE")