from sys import stdin
def input(): return stdin.readline().rstrip()

t = int(input()) - int(input())
if t >= 0: print("Congratulations, you are within the speed limit!")
elif t >= -20: print("You are speeding and your fine is $100.")
elif t >= -30: print("You are speeding and your fine is $270.")
else: print("You are speeding and your fine is $500.")