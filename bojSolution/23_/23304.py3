import sys; input = sys.stdin.readline

s = input().rstrip()

def check(x: int):
	if x==1: return True
	for i in range(x//2):
		if s[i]!=s[x-1-i]: return False
	return check(x//2)

print("AKARAKA" if check(len(s)) else "IPSELENTI")