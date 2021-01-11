import sys; input = sys.stdin.readline

h0, m0, s0 = map(int, input().split(":"))
t0 = h0*60*60 + m0*60 + s0
h1, m1, s1 = map(int, input().split(":"))
t1 = h1*60*60 + m1*60 + s1

if t1<t0: t1 += 24*60*60
t = t1-t0

print("%02d:%02d:%02d"%(t//3600, (t-(t//3600)*60*60)//60, t%60))
