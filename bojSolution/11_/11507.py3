from sys import stdin
input = stdin.readline

d = {}
s = input().rstrip()
card = [s[i*3:i*3+3] for i in range(len(s)//3)]
P,K,H,T,E = 13,13,13,13,False

for c in card:
    try:
        d[c] += 1
        E = True
        break
    except:
        d[c] = 0
        if c[0] == "P": P-=1
        if c[0] == "K": K-=1
        if c[0] == "H": H-=1
        if c[0] == "T": T-=1

if E: print("GRESKA")
else: print(P, K, H, T)