from sys import stdin
def input(): return stdin.readline().rstrip()
n=input()
s=input()
s=s.replace('LL','L')
s=s.replace('S','*S')
s=s.replace('L','*L')
s+='*'
print(min(int(n),s.count('*')))