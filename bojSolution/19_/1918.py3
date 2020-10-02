from sys import stdin
def input(): return stdin.readline().rstrip()

stk=[]
s=input()
r=""

for i in s:
    if 'A'<=i and i<='Z':
        r+=i
    elif i=='(':
        stk.append('(')
    elif i=='+' or i=='-':
        while len(stk)>0 and stk[-1]!='(':
            r+=stk[-1]
            del stk[-1]
        stk.append(i)
    elif i=='*' or i=='/':
        while len(stk)>0 and stk[-1] in ['*','/']:
            r+=stk[-1]
            del stk[-1]
        stk.append(i)
    elif i==')':
        while len(stk)>0 and stk[-1]!='(':
            r+=stk[-1]
            del stk[-1]
        del stk[-1]
        
while len(stk)>0:
    r+=stk[-1]
    del stk[-1]

print(r)