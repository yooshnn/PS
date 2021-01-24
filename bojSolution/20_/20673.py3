import sys; input = sys.stdin.readline

a, b = int(input()), int(input())
if a<=50 and b<=10: print("White")
elif b>=30: print("Red")
else: print("Yellow")