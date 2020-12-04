import sys
input = sys.stdin.readline

def ac(n):
    if n==0: return 0
    if n<=1: return 500
    if n<=3: return 300
    if n<=6: return 200
    if n<=10: return 50
    if n<=15: return 30
    if n<=21: return 10
    return 0

def bc(n):
    if n==0: return 0
    if n<=1: return 512
    if n<=3: return 256
    if n<=7: return 128
    if n<=15: return 64
    if n<=31: return 32
    return 0

for TEST in range(int(input())):
    a, b = map(int, input().split())
    print((ac(a)+bc(b))*10000)
