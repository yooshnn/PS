s = [*map(int, input().split())]
if any(s[i]>(i+2)//2*100 for i in range(9)): print("hacker")
else: print("draw" if sum(s)>=100 else "none")