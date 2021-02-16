print("Gnomes:")
exec('a,b,c=map(int,input().split());print("Ordered" if a>b>c or a<b<c else "Unordered");'*int(input()))