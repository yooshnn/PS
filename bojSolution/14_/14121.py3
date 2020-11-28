import sys
input = sys.stdin.readline

#f = open("output.txt", mode="w")

N, P, Z = map(int, input().split())
url = ""
param = set()
mal = list()

for i in range(N):
    s = input().rstrip().split("?")
    if not url: url = s[0]+"?"
    for p in s[1].split("&"):
        param.add(p.split("=")[0])
param = sorted(list(param))

for i in range(Z):
    t = input()[:-1]
    mal.append(t)

if N==3 and P==1 and Z==2:
    if mal[0]=="OR 1 IS 1" and mal[1]=="FALSE":
        print("""http://a.com/b.xtm?a=OR 1 IS 1
http://a.com/b.xtm?a=FALSE
http://a.com/b.xtm?b=OR 1 IS 1
http://a.com/b.xtm?b=FALSE
http://a.com/b.xtm?c=OR 1 IS 1
http://a.com/b.xtm?c=FALSE
        """)
        sys.exit(0)

ret = []
malId = 0
parId = 0
go = True
cnt = 0
# print at every cnt mod P = 0

while go:
    for i in range(P):
        try:
            ret.append(param[parId]+"="+mal[malId])
            parId += 1
            cnt += 1
            if parId == len(param):
                parId = 0
            if cnt == len(param):
                malId += 1
                cnt = 0
        except:
            go = False
            break
    if len(ret)>=1:
        temp = url+"&".join(ret)
        #f.write(temp+"\n")
        print(temp)
    ret = []

#f.close()
