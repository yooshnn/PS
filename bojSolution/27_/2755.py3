d={"A+": 4.3, "A0": 4.0, "A-": 3.7, "B+": 3.3, "B0": 3.0, "B-": 2.7, "C+": 2.3, "C0": 2.0, "C-": 1.7, "D+": 1.3, "D0": 1.0, "D-": 0.7, "F": 0.0}

N=int(input())
tt=0
g=0
for _ in range(N):
    s=input().split()
    t=int(s[1])
    tt+=t
    g+=t*d[s[2]]
print("%.2f"%(round(100*g/tt)/100))