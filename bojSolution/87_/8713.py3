import sys; input = sys.stdin.readline

def fm(n: int):
    if n>=0: return str(n)
    else: return "("+str(n)+")"

a, b = map(int, input().split())
res = [a+b, a-b, a*b]

if res.count(max(res))>1:
    print("NIE")
else:
    if max(res)==res[0]:
        print(fm(a)+"+"+fm(b)+"="+fm(res[0]))
    if max(res)==res[1]:
        print(fm(a)+"-"+fm(b)+"="+fm(res[1]))
    if max(res)==res[2]:
        print(fm(a)+"*"+fm(b)+"="+fm(res[2]))
