import sys; input = sys.stdin.readline

s = input().rstrip()

print("E" if s[0]=="I" else "I", end="")
print("N" if s[1]=="S" else "S", end="")
print("T" if s[2]=="F" else "F", end="")
print("J" if s[3]=="P" else "P", end="")